# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vimbax_camera_msgs:srv/FeatureInfoQuery.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FeatureInfoQuery_Request(type):
    """Metaclass of message 'FeatureInfoQuery_Request'."""

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
                'vimbax_camera_msgs.srv.FeatureInfoQuery_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__feature_info_query__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__feature_info_query__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__feature_info_query__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__feature_info_query__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__feature_info_query__request

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


class FeatureInfoQuery_Request(metaclass=Metaclass_FeatureInfoQuery_Request):
    """Message class 'FeatureInfoQuery_Request'."""

    __slots__ = [
        '_feature_names',
        '_feature_module',
    ]

    _fields_and_field_types = {
        'feature_names': 'sequence<string>',
        'feature_module': 'vimbax_camera_msgs/FeatureModule',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vimbax_camera_msgs', 'msg'], 'FeatureModule'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.feature_names = kwargs.get('feature_names', [])
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
        if self.feature_names != other.feature_names:
            return False
        if self.feature_module != other.feature_module:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def feature_names(self):
        """Message field 'feature_names'."""
        return self._feature_names

    @feature_names.setter
    def feature_names(self, value):
        if __debug__:
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
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'feature_names' field must be a set or sequence and each value of type 'str'"
        self._feature_names = value

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


class Metaclass_FeatureInfoQuery_Response(type):
    """Metaclass of message 'FeatureInfoQuery_Response'."""

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
                'vimbax_camera_msgs.srv.FeatureInfoQuery_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__feature_info_query__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__feature_info_query__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__feature_info_query__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__feature_info_query__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__feature_info_query__response

            from vimbax_camera_msgs.msg import Error
            if Error.__class__._TYPE_SUPPORT is None:
                Error.__class__.__import_type_support__()

            from vimbax_camera_msgs.msg import FeatureInfo
            if FeatureInfo.__class__._TYPE_SUPPORT is None:
                FeatureInfo.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FeatureInfoQuery_Response(metaclass=Metaclass_FeatureInfoQuery_Response):
    """Message class 'FeatureInfoQuery_Response'."""

    __slots__ = [
        '_feature_info',
        '_error',
    ]

    _fields_and_field_types = {
        'feature_info': 'sequence<vimbax_camera_msgs/FeatureInfo>',
        'error': 'vimbax_camera_msgs/Error',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['vimbax_camera_msgs', 'msg'], 'FeatureInfo')),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vimbax_camera_msgs', 'msg'], 'Error'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.feature_info = kwargs.get('feature_info', [])
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
        if self.feature_info != other.feature_info:
            return False
        if self.error != other.error:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def feature_info(self):
        """Message field 'feature_info'."""
        return self._feature_info

    @feature_info.setter
    def feature_info(self, value):
        if __debug__:
            from vimbax_camera_msgs.msg import FeatureInfo
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
                 all(isinstance(v, FeatureInfo) for v in value) and
                 True), \
                "The 'feature_info' field must be a set or sequence and each value of type 'FeatureInfo'"
        self._feature_info = value

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


class Metaclass_FeatureInfoQuery(type):
    """Metaclass of service 'FeatureInfoQuery'."""

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
                'vimbax_camera_msgs.srv.FeatureInfoQuery')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__feature_info_query

            from vimbax_camera_msgs.srv import _feature_info_query
            if _feature_info_query.Metaclass_FeatureInfoQuery_Request._TYPE_SUPPORT is None:
                _feature_info_query.Metaclass_FeatureInfoQuery_Request.__import_type_support__()
            if _feature_info_query.Metaclass_FeatureInfoQuery_Response._TYPE_SUPPORT is None:
                _feature_info_query.Metaclass_FeatureInfoQuery_Response.__import_type_support__()


class FeatureInfoQuery(metaclass=Metaclass_FeatureInfoQuery):
    from vimbax_camera_msgs.srv._feature_info_query import FeatureInfoQuery_Request as Request
    from vimbax_camera_msgs.srv._feature_info_query import FeatureInfoQuery_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
