# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vimbax_camera_msgs:srv/Status.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Status_Request(type):
    """Metaclass of message 'Status_Request'."""

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
                'vimbax_camera_msgs.srv.Status_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__status__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__status__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__status__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__status__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__status__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Status_Request(metaclass=Metaclass_Status_Request):
    """Message class 'Status_Request'."""

    __slots__ = [
    ]

    _fields_and_field_types = {
    }

    SLOT_TYPES = (
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))

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
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_Status_Response(type):
    """Metaclass of message 'Status_Response'."""

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
                'vimbax_camera_msgs.srv.Status_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__status__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__status__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__status__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__status__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__status__response

            from vimbax_camera_msgs.msg import Error
            if Error.__class__._TYPE_SUPPORT is None:
                Error.__class__.__import_type_support__()

            from vimbax_camera_msgs.msg import TriggerInfo
            if TriggerInfo.__class__._TYPE_SUPPORT is None:
                TriggerInfo.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Status_Response(metaclass=Metaclass_Status_Response):
    """Message class 'Status_Response'."""

    __slots__ = [
        '_error',
        '_display_name',
        '_model_name',
        '_device_firmware_version',
        '_device_id',
        '_device_user_id',
        '_device_serial_number',
        '_interface_id',
        '_transport_layer_id',
        '_streaming',
        '_width',
        '_height',
        '_frame_rate',
        '_pixel_format',
        '_trigger_info',
        '_ip_address',
        '_mac_address',
    ]

    _fields_and_field_types = {
        'error': 'vimbax_camera_msgs/Error',
        'display_name': 'string',
        'model_name': 'string',
        'device_firmware_version': 'string',
        'device_id': 'string',
        'device_user_id': 'string',
        'device_serial_number': 'string',
        'interface_id': 'string',
        'transport_layer_id': 'string',
        'streaming': 'boolean',
        'width': 'uint32',
        'height': 'uint32',
        'frame_rate': 'double',
        'pixel_format': 'string',
        'trigger_info': 'sequence<vimbax_camera_msgs/TriggerInfo>',
        'ip_address': 'string',
        'mac_address': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['vimbax_camera_msgs', 'msg'], 'Error'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['vimbax_camera_msgs', 'msg'], 'TriggerInfo')),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from vimbax_camera_msgs.msg import Error
        self.error = kwargs.get('error', Error())
        self.display_name = kwargs.get('display_name', str())
        self.model_name = kwargs.get('model_name', str())
        self.device_firmware_version = kwargs.get('device_firmware_version', str())
        self.device_id = kwargs.get('device_id', str())
        self.device_user_id = kwargs.get('device_user_id', str())
        self.device_serial_number = kwargs.get('device_serial_number', str())
        self.interface_id = kwargs.get('interface_id', str())
        self.transport_layer_id = kwargs.get('transport_layer_id', str())
        self.streaming = kwargs.get('streaming', bool())
        self.width = kwargs.get('width', int())
        self.height = kwargs.get('height', int())
        self.frame_rate = kwargs.get('frame_rate', float())
        self.pixel_format = kwargs.get('pixel_format', str())
        self.trigger_info = kwargs.get('trigger_info', [])
        self.ip_address = kwargs.get('ip_address', str())
        self.mac_address = kwargs.get('mac_address', str())

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
        if self.display_name != other.display_name:
            return False
        if self.model_name != other.model_name:
            return False
        if self.device_firmware_version != other.device_firmware_version:
            return False
        if self.device_id != other.device_id:
            return False
        if self.device_user_id != other.device_user_id:
            return False
        if self.device_serial_number != other.device_serial_number:
            return False
        if self.interface_id != other.interface_id:
            return False
        if self.transport_layer_id != other.transport_layer_id:
            return False
        if self.streaming != other.streaming:
            return False
        if self.width != other.width:
            return False
        if self.height != other.height:
            return False
        if self.frame_rate != other.frame_rate:
            return False
        if self.pixel_format != other.pixel_format:
            return False
        if self.trigger_info != other.trigger_info:
            return False
        if self.ip_address != other.ip_address:
            return False
        if self.mac_address != other.mac_address:
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
    def model_name(self):
        """Message field 'model_name'."""
        return self._model_name

    @model_name.setter
    def model_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'model_name' field must be of type 'str'"
        self._model_name = value

    @builtins.property
    def device_firmware_version(self):
        """Message field 'device_firmware_version'."""
        return self._device_firmware_version

    @device_firmware_version.setter
    def device_firmware_version(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'device_firmware_version' field must be of type 'str'"
        self._device_firmware_version = value

    @builtins.property
    def device_id(self):
        """Message field 'device_id'."""
        return self._device_id

    @device_id.setter
    def device_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'device_id' field must be of type 'str'"
        self._device_id = value

    @builtins.property
    def device_user_id(self):
        """Message field 'device_user_id'."""
        return self._device_user_id

    @device_user_id.setter
    def device_user_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'device_user_id' field must be of type 'str'"
        self._device_user_id = value

    @builtins.property
    def device_serial_number(self):
        """Message field 'device_serial_number'."""
        return self._device_serial_number

    @device_serial_number.setter
    def device_serial_number(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'device_serial_number' field must be of type 'str'"
        self._device_serial_number = value

    @builtins.property
    def interface_id(self):
        """Message field 'interface_id'."""
        return self._interface_id

    @interface_id.setter
    def interface_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'interface_id' field must be of type 'str'"
        self._interface_id = value

    @builtins.property
    def transport_layer_id(self):
        """Message field 'transport_layer_id'."""
        return self._transport_layer_id

    @transport_layer_id.setter
    def transport_layer_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'transport_layer_id' field must be of type 'str'"
        self._transport_layer_id = value

    @builtins.property
    def streaming(self):
        """Message field 'streaming'."""
        return self._streaming

    @streaming.setter
    def streaming(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'streaming' field must be of type 'bool'"
        self._streaming = value

    @builtins.property
    def width(self):
        """Message field 'width'."""
        return self._width

    @width.setter
    def width(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'width' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'width' field must be an unsigned integer in [0, 4294967295]"
        self._width = value

    @builtins.property
    def height(self):
        """Message field 'height'."""
        return self._height

    @height.setter
    def height(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'height' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'height' field must be an unsigned integer in [0, 4294967295]"
        self._height = value

    @builtins.property
    def frame_rate(self):
        """Message field 'frame_rate'."""
        return self._frame_rate

    @frame_rate.setter
    def frame_rate(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'frame_rate' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'frame_rate' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._frame_rate = value

    @builtins.property
    def pixel_format(self):
        """Message field 'pixel_format'."""
        return self._pixel_format

    @pixel_format.setter
    def pixel_format(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'pixel_format' field must be of type 'str'"
        self._pixel_format = value

    @builtins.property
    def trigger_info(self):
        """Message field 'trigger_info'."""
        return self._trigger_info

    @trigger_info.setter
    def trigger_info(self, value):
        if __debug__:
            from vimbax_camera_msgs.msg import TriggerInfo
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, TriggerInfo) for v in value) and
                 True), \
                "The 'trigger_info' field must be a set or sequence and each value of type 'TriggerInfo'"
        self._trigger_info = value

    @builtins.property
    def ip_address(self):
        """Message field 'ip_address'."""
        return self._ip_address

    @ip_address.setter
    def ip_address(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'ip_address' field must be of type 'str'"
        self._ip_address = value

    @builtins.property
    def mac_address(self):
        """Message field 'mac_address'."""
        return self._mac_address

    @mac_address.setter
    def mac_address(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'mac_address' field must be of type 'str'"
        self._mac_address = value


class Metaclass_Status(type):
    """Metaclass of service 'Status'."""

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
                'vimbax_camera_msgs.srv.Status')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__status

            from vimbax_camera_msgs.srv import _status
            if _status.Metaclass_Status_Request._TYPE_SUPPORT is None:
                _status.Metaclass_Status_Request.__import_type_support__()
            if _status.Metaclass_Status_Response._TYPE_SUPPORT is None:
                _status.Metaclass_Status_Response.__import_type_support__()


class Status(metaclass=Metaclass_Status):
    from vimbax_camera_msgs.srv._status import Status_Request as Request
    from vimbax_camera_msgs.srv._status import Status_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
