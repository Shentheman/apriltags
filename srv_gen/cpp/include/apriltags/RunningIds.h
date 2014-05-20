/* Auto-generated by genmsg_cpp for file /homes/awalsman/ros/local/pr-ros-pkg/trunk/perception_utils/apriltags/srv/RunningIds.srv */
#ifndef APRILTAGS_SERVICE_RUNNINGIDS_H
#define APRILTAGS_SERVICE_RUNNINGIDS_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "ros/service_traits.h"




namespace apriltags
{
template <class ContainerAllocator>
struct RunningIdsRequest_ {
  typedef RunningIdsRequest_<ContainerAllocator> Type;

  RunningIdsRequest_()
  {
  }

  RunningIdsRequest_(const ContainerAllocator& _alloc)
  {
  }


  typedef boost::shared_ptr< ::apriltags::RunningIdsRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::apriltags::RunningIdsRequest_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct RunningIdsRequest
typedef  ::apriltags::RunningIdsRequest_<std::allocator<void> > RunningIdsRequest;

typedef boost::shared_ptr< ::apriltags::RunningIdsRequest> RunningIdsRequestPtr;
typedef boost::shared_ptr< ::apriltags::RunningIdsRequest const> RunningIdsRequestConstPtr;


template <class ContainerAllocator>
struct RunningIdsResponse_ {
  typedef RunningIdsResponse_<ContainerAllocator> Type;

  RunningIdsResponse_()
  : ids()
  {
  }

  RunningIdsResponse_(const ContainerAllocator& _alloc)
  : ids(_alloc)
  {
  }

  typedef std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other >  _ids_type;
  std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other >  ids;


  typedef boost::shared_ptr< ::apriltags::RunningIdsResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::apriltags::RunningIdsResponse_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct RunningIdsResponse
typedef  ::apriltags::RunningIdsResponse_<std::allocator<void> > RunningIdsResponse;

typedef boost::shared_ptr< ::apriltags::RunningIdsResponse> RunningIdsResponsePtr;
typedef boost::shared_ptr< ::apriltags::RunningIdsResponse const> RunningIdsResponseConstPtr;

struct RunningIds
{

typedef RunningIdsRequest Request;
typedef RunningIdsResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;
}; // struct RunningIds
} // namespace apriltags

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::apriltags::RunningIdsRequest_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::apriltags::RunningIdsRequest_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::apriltags::RunningIdsRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const  ::apriltags::RunningIdsRequest_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::apriltags::RunningIdsRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "apriltags/RunningIdsRequest";
  }

  static const char* value(const  ::apriltags::RunningIdsRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::apriltags::RunningIdsRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "\n\
";
  }

  static const char* value(const  ::apriltags::RunningIdsRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::apriltags::RunningIdsRequest_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros


namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::apriltags::RunningIdsResponse_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::apriltags::RunningIdsResponse_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::apriltags::RunningIdsResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "4f22efebf407aadba2ecc69df353d113";
  }

  static const char* value(const  ::apriltags::RunningIdsResponse_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x4f22efebf407aadbULL;
  static const uint64_t static_value2 = 0xa2ecc69df353d113ULL;
};

template<class ContainerAllocator>
struct DataType< ::apriltags::RunningIdsResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "apriltags/RunningIdsResponse";
  }

  static const char* value(const  ::apriltags::RunningIdsResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::apriltags::RunningIdsResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "int32[] ids\n\
\n\
\n\
";
  }

  static const char* value(const  ::apriltags::RunningIdsResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::apriltags::RunningIdsRequest_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct RunningIdsRequest_
} // namespace serialization
} // namespace ros


namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::apriltags::RunningIdsResponse_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.ids);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct RunningIdsResponse_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace service_traits
{
template<>
struct MD5Sum<apriltags::RunningIds> {
  static const char* value() 
  {
    return "4f22efebf407aadba2ecc69df353d113";
  }

  static const char* value(const apriltags::RunningIds&) { return value(); } 
};

template<>
struct DataType<apriltags::RunningIds> {
  static const char* value() 
  {
    return "apriltags/RunningIds";
  }

  static const char* value(const apriltags::RunningIds&) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<apriltags::RunningIdsRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "4f22efebf407aadba2ecc69df353d113";
  }

  static const char* value(const apriltags::RunningIdsRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<apriltags::RunningIdsRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "apriltags/RunningIds";
  }

  static const char* value(const apriltags::RunningIdsRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<apriltags::RunningIdsResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "4f22efebf407aadba2ecc69df353d113";
  }

  static const char* value(const apriltags::RunningIdsResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<apriltags::RunningIdsResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "apriltags/RunningIds";
  }

  static const char* value(const apriltags::RunningIdsResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace service_traits
} // namespace ros

#endif // APRILTAGS_SERVICE_RUNNINGIDS_H
