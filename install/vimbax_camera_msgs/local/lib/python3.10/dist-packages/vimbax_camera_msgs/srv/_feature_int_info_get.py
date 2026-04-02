# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vimbax_camera_msgs:srv/FeatureIntInfoGet.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FeatureIntInfoGet_Request(type):
    """Metaclass of message 'FeatureIntInfoGet_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('vimbax_camera_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'vimbax_camera_msgs.srv.FeatureIntInfoGet_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__feature_int_info_get__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__feature_int_info_get__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__feature_int_info_get__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__feature_int_info_get__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__feature_int_info_get__request

            from vimbax_camera_msgs.msg import FeatureModule
            if FeatureModule.__class__._TYPE_SUPPORT is None:
                FeatureModule.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FeatureIntInfoGet_Request(metaclass=Metaclass_FeatureIntInfoGet_Request):
    """Message class 'FeatureIntInfoGet_Request'."""

    __slots__ = [
        '_feature_name',
        '_feature_module',
    ]

    _fields_and_field_types = {
        'feature_name': 'string',
        'feature_module': 'vimbax_camera_msgs/FeatureModule',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vimbax_camera_msgs', 'msg'], 'FeatureModule'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.feature_name = kwargs.get('feature_name', str())
        from vimbax_camera_msgs.msg import FeatureModule
        self.feature_module = kwargs.get('feature_module', FeatureModule())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.feature_name != other.feature_name:
            return False
        if self.feature_module != other.feature_module:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def feature_name(self):
        """Message field 'feature_name'."""
        return self._feature_name

    @feature_name.setter
    def feature_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'feature_name' field must be of type 'str'"
        self._feature_name = value

    @builtins.property
    def feature_module(self):
        """Message field 'feature_module'."""
        return self._feature_module

    @feature_module.setter
    def feature_module(self, value):
        if __debug__:
            from vimbax_camera_msgs.msg import FeatureModule
            assert \
                isinstance(value, FeatureModule), \
                "The 'feature_module' field must be a sub message of type 'FeatureModule'"
        self._feature_module = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_FeatureIntInfoGet_Response(type):
    """Metaclass of message 'FeatureIntInfoGet_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('vimbax_camera_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'vimbax_camera_msgs.srv.FeatureIntInfoGet_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__feature_int_info_get__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__feature_int_info_get__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__feature_int_info_get__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__feature_int_info_get__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__feature_int_info_get__response

            from vimbax_camera_msgs.msg import Error
            if Error.__class__._TYPE_SUPPORT is None:
                Error.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FeatureIntInfoGet_Response(metaclass=Metaclass_FeatureIntInfoGet_Response):
    """Message class 'FeatureIntInfoGet_Response'."""

    __slots__ = [
        '_min',
        '_max',
        '_inc',
        '_error',
    ]

    _fields_and_field_types = {
        'min': 'int64',
        'max': 'int64',
        'inc': 'int64',
        'error': 'vimbax_camera_msgs/Error',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vimbax_camera_msgs', 'msg'], 'Error'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.min = kwargs.get('min', int())
        self.max = kwargs.get('max', int())
        self.inc = kwargs.get('inc', int())
        from vimbax_camera_msgs.msg import Error
        self.error = kwargs.get('error', Error())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.min != other.min:
            return False
        if self.max != other.max:
            return False
        if self.inc != other.inc:
            return False
        if self.error != other.error:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property  # noqa: A003
    def min(self):  # noqa: A003
        """Message field 'min'."""
        return self._min

    @min.setter  # noqa: A003
    def min(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'min' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'min' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._min = value

    @builtins.property  # noqa: A003
    def max(self):  # noqa: A003
        """Message field 'max'."""
        return self._max

    @max.setter  # noqa: A003
    def max(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'max' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'max' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._max = value

    @builtins.property
    def inc(self):
        """Message field 'inc'."""
        return self._inc

    @inc.setter
    def inc(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'inc' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'inc' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._inc = value

    @builtins.property
    def error(self):
        """Message field 'error'."""
        return self._error

    @error.setter
    def error(self, value):
        if __debug__:
            from vimbax_camera_msgs.msg import Error
            assert \
                isinstance(value, Error), \
                "The 'error' field must be a sub message of type 'Error'"
        self._error = value


class Metaclass_FeatureIntInfoGet(type):
    """Metaclass of service 'FeatureIntInfoGet'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('vimbax_camera_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'vimbax_camera_msgs.srv.FeatureIntInfoGet')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__feature_int_info_get

            from vimbax_camera_msgs.srv import _feature_int_info_get
            if _feature_int_info_get.Metaclass_FeatureIntInfoGet_Request._TYPE_SUPPORT is None:
                _feature_int_info_get.Metaclass_FeatureIntInfoGet_Request.__import_type_support__()
            if _feature_int_info_get.Metaclass_FeatureIntInfoGet_Response._TYPE_SUPPORT is None:
                _feature_int_info_get.Metaclass_FeatureIntInfoGet_Response.__import_type_support__()


class FeatureIntInfoGet(metaclass=Metaclass_FeatureIntInfoGet):
    from vimbax_camera_msgs.srv._feature_int_info_get import FeatureIntInfoGet_Request as Request
    from vimbax_camera_msgs.srv._feature_int_info_get import FeatureIntInfoGet_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
