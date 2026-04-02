// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from vimbax_camera_msgs:srv/FeatureInfoQuery.idl
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
#include "vimbax_camera_msgs/srv/detail/feature_info_query__struct.h"
#include "vimbax_camera_msgs/srv/detail/feature_info_query__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"
#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

bool vimbax_camera_msgs__msg__feature_module__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vimbax_camera_msgs__msg__feature_module__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool vimbax_camera_msgs__srv__feature_info_query__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[68];
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
    assert(strncmp("vimbax_camera_msgs.srv._feature_info_query.FeatureInfoQuery_Request", full_classname_dest, 67) == 0);
  }
  vimbax_camera_msgs__srv__FeatureInfoQuery_Request * ros_message = _ros_message;
  {  // feature_names
    PyObject * field = PyObject_GetAttrString(_pymsg, "feature_names");
    if (!field) {
      return false;
    }
    {
      PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'feature_names'");
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
      if (!rosidl_runtime_c__String__Sequence__init(&(ros_message->feature_names), size)) {
        PyErr_SetString(PyExc_RuntimeError, "unable to create String__Sequence ros_message");
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
      rosidl_runtime_c__String * dest = ros_message->feature_names.data;
      for (Py_ssize_t i = 0; i < size; ++i) {
        PyObject * item = PySequence_Fast_GET_ITEM(seq_field, i);
        if (!item) {
          Py_DECREF(seq_field);
          Py_DECREF(field);
          return false;
        }
        assert(PyUnicode_Check(item));
        PyObject * encoded_item = PyUnicode_AsUTF8String(item);
        if (!encoded_item) {
          Py_DECREF(seq_field);
          Py_DECREF(field);
          return false;
        }
        rosidl_runtime_c__String__assign(&dest[i], PyBytes_AS_STRING(encoded_item));
        Py_DECREF(encoded_item);
      }
      Py_DECREF(seq_field);
    }
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
PyObject * vimbax_camera_msgs__srv__feature_info_query__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of FeatureInfoQuery_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("vimbax_camera_msgs.srv._feature_info_query");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "FeatureInfoQuery_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  vimbax_camera_msgs__srv__FeatureInfoQuery_Request * ros_message = (vimbax_camera_msgs__srv__FeatureInfoQuery_Request *)raw_ros_message;
  {  // feature_names
    PyObject * field = NULL;
    size_t size = ros_message->feature_names.size;
    rosidl_runtime_c__String * src = ros_message->feature_names.data;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    for (size_t i = 0; i < size; ++i) {
      PyObject * decoded_item = PyUnicode_DecodeUTF8(src[i].data, strlen(src[i].data), "replace");
      if (!decoded_item) {
        return NULL;
      }
      int rc = PyList_SetItem(field, i, decoded_item);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "feature_names", field);
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
// #include "vimbax_camera_msgs/srv/detail/feature_info_query__struct.h"
// already included above
// #include "vimbax_camera_msgs/srv/detail/feature_info_query__functions.h"

// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "vimbax_camera_msgs/msg/detail/feature_info__functions.h"
// end nested array functions include
bool vimbax_camera_msgs__msg__feature_info__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vimbax_camera_msgs__msg__feature_info__convert_to_py(void * raw_ros_message);
bool vimbax_camera_msgs__msg__error__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vimbax_camera_msgs__msg__error__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool vimbax_camera_msgs__srv__feature_info_query__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[69];
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
    assert(strncmp("vimbax_camera_msgs.srv._feature_info_query.FeatureInfoQuery_Response", full_classname_dest, 68) == 0);
  }
  vimbax_camera_msgs__srv__FeatureInfoQuery_Response * ros_message = _ros_message;
  {  // feature_info
    PyObject * field = PyObject_GetAttrString(_pymsg, "feature_info");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'feature_info'");
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
    if (!vimbax_camera_msgs__msg__FeatureInfo__Sequence__init(&(ros_message->feature_info), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create vimbax_camera_msgs__msg__FeatureInfo__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    vimbax_camera_msgs__msg__FeatureInfo * dest = ros_message->feature_info.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!vimbax_camera_msgs__msg__feature_info__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
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
PyObject * vimbax_camera_msgs__srv__feature_info_query__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of FeatureInfoQuery_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("vimbax_camera_msgs.srv._feature_info_query");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "FeatureInfoQuery_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  vimbax_camera_msgs__srv__FeatureInfoQuery_Response * ros_message = (vimbax_camera_msgs__srv__FeatureInfoQuery_Response *)raw_ros_message;
  {  // feature_info
    PyObject * field = NULL;
    size_t size = ros_message->feature_info.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    vimbax_camera_msgs__msg__FeatureInfo * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->feature_info.data[i]);
      PyObject * pyitem = vimbax_camera_msgs__msg__feature_info__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "feature_info", field);
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
