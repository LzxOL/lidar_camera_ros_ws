
import numpy as np


def generate_3d_lut_from_ccm(ccm, lut_size=33):
    """
    将 3x3 CCM 矩阵展开为 3D LUT

    原理: CCM 描述的是线性 RGB 空间中的颜色转换
        R_out = ccm[0,0]*R_in + ccm[0,1]*G_in + ccm[0,2]*B_in
        G_out = ccm[1,0]*R_in + ccm[1,1]*G_in + ccm[1,2]*B_in
        B_out = ccm[2,0]*R_in + ccm[2,1]*G_in + ccm[2,2]*B_in

    对于线性空间，3x3 CCM 的效果完全可以用 LUT 来表示：
    - LUT 中每个格子点 (r,g,b) 的值 = CCM @ [r, g, b]^T
    - 非格子点的值通过三线性插值获得

    参数:
        ccm: 3x3 numpy array, float64, 线性 RGB 颜色转换矩阵
        lut_size: LUT 的大小，默认 33 (即 32^3 = 32768 个格子点)

    返回:
        lut: (lut_size, lut_size, lut_size, 3) float32, range [0, 1]
    """
    if ccm.shape != (3, 3):
        raise ValueError(f"CCM must be 3x3, got shape {ccm.shape}")

    lut_size = int(lut_size)
    lut = np.zeros((lut_size, lut_size, lut_size, 3), dtype=np.float32)

    for r_idx in range(lut_size):
        for g_idx in range(lut_size):
            for b_idx in range(lut_size):
                r_norm = r_idx / (lut_size - 1)
                g_norm = g_idx / (lut_size - 1)
                b_norm = b_idx / (lut_size - 1)

                input_vec = np.array([r_norm, g_norm, b_norm], dtype=np.float64)
                output_vec = ccm @ input_vec

                lut[r_idx, g_idx, b_idx] = output_vec.astype(np.float32)

    lut = np.clip(lut, 0.0, 1.0)
    return lut


def apply_3d_lut(image_rgb_uint8, lut):
    """
    对 RGB uint8 图像应用 3D LUT（三线性插值）

    参数:
        image_rgb_uint8: H x W x 3, uint8, RGB 格式
        lut: S x S x S x 3, float32/float64, range [0, 1]

    返回:
        out_uint8: H x W x 3, uint8, RGB 格式
    """
    img = image_rgb_uint8.astype(np.float32) / 255.0
    size = lut.shape[0]

    coords = img * (size - 1)

    r = coords[..., 0]
    g = coords[..., 1]
    b = coords[..., 2]

    r0 = np.floor(r).astype(np.int32)
    g0 = np.floor(g).astype(np.int32)
    b0 = np.floor(b).astype(np.int32)

    r1 = np.clip(r0 + 1, 0, size - 1)
    g1 = np.clip(g0 + 1, 0, size - 1)
    b1 = np.clip(b0 + 1, 0, size - 1)

    dr = (r - r0)[..., None]
    dg = (g - g0)[..., None]
    db = (b - b0)[..., None]

    c000 = lut[r0, g0, b0]
    c001 = lut[r0, g0, b1]
    c010 = lut[r0, g1, b0]
    c011 = lut[r0, g1, b1]
    c100 = lut[r1, g0, b0]
    c101 = lut[r1, g0, b1]
    c110 = lut[r1, g1, b0]
    c111 = lut[r1, g1, b1]

    c00 = c000 * (1.0 - db) + c001 * db
    c01 = c010 * (1.0 - db) + c011 * db
    c10 = c100 * (1.0 - db) + c101 * db
    c11 = c110 * (1.0 - db) + c111 * db

    c0 = c00 * (1.0 - dg) + c01 * dg
    c1 = c10 * (1.0 - dg) + c11 * dg

    out = c0 * (1.0 - dr) + c1 * dr
    out = np.clip(out * 255.0, 0, 255).astype(np.uint8)

    return out
