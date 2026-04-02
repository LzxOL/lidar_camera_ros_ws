// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from vimbax_camera_msgs:msg/FeatureFlags.idl
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
#include "vimbax_camera_msgs/msg/detail/feature_flags__struct.h"
#include "vimbax_camera_msgs/msg/detail/feature_flags__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool vimbax_camera_msgs__msg__feature_flags__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[51];
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
    assert(strncmp("vimbax_camera_msgs.msg._feature_flags.FeatureFlags", full_classname_dest, 50) == 0);
  }
  vimbax_camera_msgs__msg__FeatureFlags * ros_message = _ros_message;
  {  // flag_none
    PyObject * field = PyObject_GetAttrString(_pymsg, "flag_none");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->flag_none = (Py_True == field);
    Py_DECREF(field);
  }
  {  // flag_read
    PyObject * field = PyObject_GetAttrString(_pymsg, "flag_read");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->flag_read = (Py_True == field);
    Py_DECREF(field);
  }
  {  // flag_write
    PyObject * field = PyObject_GetAttrString(_pymsg, "flag_write");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->flag_write = (Py_True == field);
    Py_DECREF(field);
  }
  {  // flag_volatile
    PyObject * field = PyObject_GetAttrString(_pymsg, "flag_volatile");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->flag_volatile = (Py_True == field);
    Py_DECREF(field);
  }
  {  // flag_modify_write
    PyObject * field = PyObject_GetAttrString(_pymsg, "flag_modify_write");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->flag_modify_write = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * vimbax_camera_msgs__msg__feature_flags__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of FeatureFlags */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("vimbax_camera_msgs.msg._feature_flags");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "FeatureFlags");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  vimbax_camera_msgs__msg__FeatureFlags * ros_message = (vimbax_camera_msgs__msg__FeatureFlags *)raw_ros_message;
  {  // flag_none
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->flag_none ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "flag_none", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // flag_read
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->flag_read ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "flag_read", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // flag_write
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->flag_write ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "flag_write", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // flag_volatile
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->flag_volatile ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "flag_volatile", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // flag_modify_write
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->flag_modify_write ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "flag_modify_write", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
