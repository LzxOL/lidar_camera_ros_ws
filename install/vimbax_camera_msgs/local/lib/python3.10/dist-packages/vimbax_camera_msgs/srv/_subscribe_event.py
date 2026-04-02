# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vimbax_camera_msgs:srv/SubscribeEvent.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SubscribeEvent_Request(type):
    """Metaclass of message 'SubscribeEvent_Request'."""

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
                'vimbax_camera_msgs.srv.SubscribeEvent_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__subscribe_event__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__subscribe_event__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__subscribe_event__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__subscribe_event__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__subscribe_event__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SubscribeEvent_Request(metaclass=Metaclass_SubscribeEvent_Request):
    """Message class 'SubscribeEvent_Request'."""

    __slots__ = [
        '_name',
    ]

    _fields_and_field_types = {
        'name': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.name = kwargs.get('name', str())

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


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SubscribeEvent_Response(type):
    """Metaclass of message 'SubscribeEvent_Response'."""

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
                'vimbax_camera_msgs.srv.SubscribeEvent_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__subscribe_event__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__subscribe_event__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__subscribe_event__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__subscribe_event__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__subscribe_event__response

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


class SubscribeEvent_Response(metaclass=Metaclass_SubscribeEvent_Response):
    """Message class 'SubscribeEvent_Response'."""

    __slots__ = [
        '_error',
    ]

    _fields_and_field_types = {
        'error': 'vimbax_camera_msgs/Error',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['vimbax_camera_msgs', 'msg'], 'Error'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
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
        if self.error != other.error:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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


class Metaclass_SubscribeEvent(type):
    """Metaclass of service 'SubscribeEvent'."""

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
                'vimbax_camera_msgs.srv.SubscribeEvent')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__subscribe_event

            from vimbax_camera_msgs.srv import _subscribe_event
            if _subscribe_event.Metaclass_SubscribeEvent_Request._TYPE_SUPPORT is None:
                _subscribe_event.Metaclass_SubscribeEvent_Request.__import_type_support__()
            if _subscribe_event.Metaclass_SubscribeEvent_Response._TYPE_SUPPORT is None:
                _subscribe_event.Metaclass_SubscribeEvent_Response.__import_type_support__()


class SubscribeEvent(metaclass=Metaclass_SubscribeEvent):
    from vimbax_camera_msgs.srv._subscribe_event import SubscribeEvent_Request as Request
    from vimbax_camera_msgs.srv._subscribe_event import SubscribeEvent_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
