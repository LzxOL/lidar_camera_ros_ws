# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vimbax_camera_msgs:msg/FeatureInfo.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FeatureInfo(type):
    """Metaclass of message 'FeatureInfo'."""

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
                'vimbax_camera_msgs.msg.FeatureInfo')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__feature_info
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__feature_info
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__feature_info
            cls._TYPE_SUPPORT = module.type_support_msg__msg__feature_info
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__feature_info

            from vimbax_camera_msgs.msg import FeatureFlags
            if FeatureFlags.__class__._TYPE_SUPPORT is None:
                FeatureFlags.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FeatureInfo(metaclass=Metaclass_FeatureInfo):
    """Message class 'FeatureInfo'."""

    __slots__ = [
        '_name',
        '_category',
        '_display_name',
        '_sfnc_namespace',
        '_unit',
        '_data_type',
        '_flags',
        '_polling_time',
    ]

    _fields_and_field_types = {
        'name': 'string',
        'category': 'string',
        'display_name': 'string',
        'sfnc_namespace': 'string',
        'unit': 'string',
        'data_type': 'uint32',
        'flags': 'vimbax_camera_msgs/FeatureFlags',
        'polling_time': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vimbax_camera_msgs', 'msg'], 'FeatureFlags'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.name = kwargs.get('name', str())
        self.category = kwargs.get('category', str())
        self.display_name = kwargs.get('display_name', str())
        self.sfnc_namespace = kwargs.get('sfnc_namespace', str())
        self.unit = kwargs.get('unit', str())
        self.data_type = kwargs.get('data_type', int())
        from vimbax_camera_msgs.msg import FeatureFlags
        self.flags = kwargs.get('flags', FeatureFlags())
        self.polling_time = kwargs.get('polling_time', int())

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
        if self.name != other.name:
            return False
        if self.category != other.category:
            return False
        if self.display_name != other.display_name:
            return False
        if self.sfnc_namespace != other.sfnc_namespace:
            return False
        if self.unit != other.unit:
            return False
        if self.data_type != other.data_type:
            return False
        if self.flags != other.flags:
            return False
        if self.polling_time != other.polling_time:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def name(self):
        """Message field 'name'."""
        return self._name

    @name.setter
    def name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'name' field must be of type 'str'"
        self._name = value

    @builtins.property
    def category(self):
        """Message field 'category'."""
        return self._category

    @category.setter
    def category(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'category' field must be of type 'str'"
        self._category = value

    @builtins.property
    def display_name(self):
        """Message field 'display_name'."""
        return self._display_name

    @display_name.setter
    def display_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'display_name' field must be of type 'str'"
        self._display_name = value

    @builtins.property
    def sfnc_namespace(self):
        """Message field 'sfnc_namespace'."""
        return self._sfnc_namespace

    @sfnc_namespace.setter
    def sfnc_namespace(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'sfnc_namespace' field must be of type 'str'"
        self._sfnc_namespace = value

    @builtins.property
    def unit(self):
        """Message field 'unit'."""
        return self._unit

    @unit.setter
    def unit(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'unit' field must be of type 'str'"
        self._unit = value

    @builtins.property
    def data_type(self):
        """Message field 'data_type'."""
        return self._data_type

    @data_type.setter
    def data_type(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'data_type' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'data_type' field must be an unsigned integer in [0, 4294967295]"
        self._data_type = value

    @builtins.property
    def flags(self):
        """Message field 'flags'."""
        return self._flags

    @flags.setter
    def flags(self, value):
        if __debug__:
            from vimbax_camera_msgs.msg import FeatureFlags
            assert \
                isinstance(value, FeatureFlags), \
                "The 'flags' field must be a sub message of type 'FeatureFlags'"
        self._flags = value

    @builtins.property
    def polling_time(self):
        """Message field 'polling_time'."""
        return self._polling_time

    @polling_time.setter
    def polling_time(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'polling_time' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'polling_time' field must be an unsigned integer in [0, 4294967295]"
        self._polling_time = value
