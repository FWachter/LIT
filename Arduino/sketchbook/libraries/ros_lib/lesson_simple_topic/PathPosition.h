#ifndef _ROS_lesson_simple_topic_PathPosition_h
#define _ROS_lesson_simple_topic_PathPosition_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace lesson_simple_topic
{

  class PathPosition : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float x;
      float y;
      float angle;

    PathPosition():
      header(),
      x(0),
      y(0),
      angle(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      offset += serializeAvrFloat64(outbuffer + offset, this->angle);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->angle));
     return offset;
    }

    const char * getType(){ return "lesson_simple_topic/PathPosition"; };
    const char * getMD5(){ return "0dddc77aef0a3a360e11329b0db00bf9"; };

  };

}
#endif