# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vimbax_camera_msgs:msg/FeatureFlags.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FeatureFlags(type):
    """Metaclass of message 'FeatureFlags'."""

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
                'vimbax_camera_msgs.msg.FeatureFlags')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__feature_flags
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__feature_flags
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__feature_flags
            cls._TYPE_SUPPORT = module.type_support_msg__msg__feature_flags
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__feature_flags

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FeatureFlags(metaclass=Metaclass_FeatureFlags):
    """Message class 'FeatureFlags'."""

    __slots__ = [
        '_flag_none',
        '_flag_read',
        '_flag_write',
        '_flag_volatile',
        '_flag_modify_write',
    ]

    _fields_and_field_types = {
        'flag_none': 'boolean',
        'flag_read': 'boolean',
        'flag_write': 'boolean',
        'flag_volatile': 'boolean',
        'flag_modify_write': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.flag_none = kwargs.get('flag_none', bool())
        self.flag_read = kwargs.get('flag_read', bool())
        self.flag_write = kwargs.get('flag_write', bool())
        self.flag_volatile = kwargs.get('flag_volatile', bool())
        self.flag_modify_write = kwargs.get('flag_modify_write', bool())

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
        if self.flag_none != other.flag_none:
            return False
        if self.flag_read != other.flag_read:
            return False
        if self.flag_write != other.flag_write:
            return False
        if self.flag_volatile != other.flag_volatile:
            return False
        if self.flag_modify_write != other.flag_modify_write:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def flag_none(self):
        """Message field 'flag_none'."""
        return self._flag_none

    @flag_none.setter
    def flag_none(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'flag_none' field must be of type 'bool'"
        self._flag_none = value

    @builtins.property
    def flag_read(self):
        """Message field 'flag_read'."""
        return self._flag_read

    @flag_read.setter
    def flag_read(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'flag_read' field must be of type 'bool'"
        self._flag_read = value

    @builtins.property
    def flag_write(self):
        """Message field 'flag_write'."""
        return self._flag_write

    @flag_write.setter
    def flag_write(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'flag_write' field must be of type 'bool'"
        self._flag_write = value

    @builtins.property
    def flag_volatile(self):
        """Message field 'flag_volatile'."""
        return self._flag_volatile

    @flag_volatile.setter
    def flag_volatile(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'flag_volatile' field must be of type 'bool'"
        self._flag_volatile = value

    @builtins.property
    def flag_modify_write(self):
        """Message field 'flag_modify_write'."""
        return self._flag_modify_write

    @flag_modify_write.setter
    def flag_modify_write(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'flag_modify_write' field must be of type 'bool'"
        self._flag_modify_write = value
