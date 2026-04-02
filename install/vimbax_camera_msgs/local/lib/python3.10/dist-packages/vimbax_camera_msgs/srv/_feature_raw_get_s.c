// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from vimbax_camera_msgs:srv/FeatureRawGet.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "vimbax_camera_msgs/srv/detail/feature_raw_get__struct.h"
#include "vimbax_camera_msgs/srv/detail/feature_raw_get__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

bool vimbax_camera_msgs__msg__feature_module__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vimbax_camera_msgs__msg__feature_module__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool vimbax_camera_msgs__srv__feature_raw_get__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[62];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("vimbax_camera_msgs.srv._feature_raw_get.FeatureRawGet_Request", full_classname_dest, 61) == 0);
  }
  vimbax_camera_msgs__srv__FeatureRawGet_Request * ros_message = _ros_message;
  {  // feature_name
    PyObject * field = PyObject_GetAttrString(_pymsg, "feature_name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->feature_name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // feature_module
    PyObject * field = PyObject_GetAttrString(_pymsg, "feature_module");
    if (!field) {
      return false;
    }
    if (!vimbax_camera_msgs__msg__feature_module__convert_from_py(field, &ros_message->feature_module)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * vimbax_camera_msgs__srv__feature_raw_get__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of FeatureRawGet_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("vimbax_camera_msgs.srv._feature_raw_get");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "FeatureRawGet_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  vimbax_camera_msgs__srv__FeatureRawGet_Request * ros_message = (vimbax_camera_msgs__srv__FeatureRawGet_Request *)raw_ros_message;
  {  // feature_name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->feature_name.data,
      strlen(ros_message->feature_name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "feature_name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // feature_module
    PyObject * field = NULL;
    field = vimbax_camera_msgs__msg__feature_module__convert_to_py(&ros_message->feature_module);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "feature_module", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "vimbax_camera_msgs/srv/detail/feature_raw_get__struct.h"
// already included above
// #include "vimbax_camera_msgs/srv/detail/feature_raw_get__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool vimbax_camera_msgs__msg__error__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vimbax_camera_msgs__msg__error__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool vimbax_camera_msgs__srv__feature_raw_get__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[63];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("vimbax_camera_msgs.srv._feature_raw_get.FeatureRawGet_Response", full_classname_dest, 62) == 0);
  }
  vimbax_camera_msgs__srv__FeatureRawGet_Response * ros_message = _ros_message;
  {  // buffer
    PyObject * field = PyObject_GetAttrString(_pymsg, "buffer");
    if (!field) {
      return false;
    }
    if (PyObject_CheckBuffer(field)) {
      // Optimization for converting arrays of primitives
      Py_buffer view;
      int rc = PyObject_GetBuffer(field, &view, PyBUF_SIMPLE);
      if (rc < 0) {
        Py_DECREF(field);
        return false;
      }
      Py_ssize_t size = view.len / sizeof(uint8_t);
      if (!rosidl_runtime_c__octet__Sequence__init(&(ros_message->buffer), size)) {
        PyErr_SetString(PyExc_RuntimeError, "unable to create octet__Sequence ros_message");
        PyBuffer_Release(&view);
        Py_DECREF(field);
        return false;
      }
      uint8_t * dest = ros_message->buffer.data;
      rc = PyBuffer_ToContiguous(dest, &view, view.len, 'C');
      if (rc < 0) {
        PyBuffer_Release(&view);
        Py_DECREF(field);
        return false;
      }
      PyBuffer_Release(&view);
    } else {
      PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'buffer'");
      if (!seq_field) {
        Py_DECREF(field);
        return false;
      }
      Py_ssize_t size = PySequence_Size(field);
      if (-1 == size) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
      if (!rosidl_runtime_c__octet__Sequence__init(&(ros_message->buffer), size)) {
        PyErr_SetString(PyExc_RuntimeError, "unable to create octet__Sequence ros_message");
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
      uint8_t * dest = ros_message->buffer.data;
      for (Py_ssize_t i = 0; i < size; ++i) {
        PyObject * item = PySequence_Fast_GET_ITEM(seq_field, i);
        if (!item) {
          Py_DECREF(seq_field);
          Py_DECREF(field);
          return false;
        }
        assert(PyBytes_Check(item));
        uint8_t tmp = PyBytes_AS_STRING(item)[0];
        memcpy(&dest[i], &tmp, sizeof(uint8_t));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // buffer_size
    PyObject * field = PyObject_GetAttrString(_pymsg, "buffer_size");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->buffer_size = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // error
    PyObject * field = PyObject_GetAttrString(_pymsg, "error");
    if (!field) {
      return false;
    }
    if (!vimbax_camera_msgs__msg__error__convert_from_py(field, &ros_message->error)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * vimbax_camera_msgs__srv__feature_raw_get__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of FeatureRawGet_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("vimbax_camera_msgs.srv._feature_raw_get");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "FeatureRawGet_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  vimbax_camera_msgs__srv__FeatureRawGet_Response * ros_message = (vimbax_camera_msgs__srv__FeatureRawGet_Response *)raw_ros_message;
  {  // buffer
    PyObject * field = NULL;
    size_t size = ros_message->buffer.size;
    uint8_t * src = ros_message->buffer.data;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    for (size_t i = 0; i < size; ++i) {
      int rc = PyList_SetItem(field, i, PyBytes_FromStringAndSize((const char *)&src[i], 1));
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "buffer", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // buffer_size
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->buffer_size);
    {
      int rc = PyObject_SetAttrString(_pymessage, "buffer_size", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // error
    PyObject * field = NULL;
    field = vimbax_camera_msgs__msg__error__convert_to_py(&ros_message->error);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "error", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
