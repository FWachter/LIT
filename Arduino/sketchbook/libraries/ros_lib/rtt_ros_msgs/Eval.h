#ifndef _ROS_SERVICE_Eval_h
#define _ROS_SERVICE_Eval_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rtt_ros_msgs
{

static const char EVAL[] = "rtt_ros_msgs/Eval";

  class EvalRequest : public ros::Msg
  {
    public:
      const char* code;

    EvalRequest():
      code("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_code = strlen(this->code);
      memcpy(outbuffer + offset, &length_code, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->code, length_code);
      offset += length_code;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_code;
      memcpy(&length_code, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_code; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_code-1]=0;
      this->code = (char *)(inbuffer + offset-1);
      offset += length_code;
     return offset;
    }

    const char * getType(){ return EVAL; };
    const char * getMD5(){ return "9d589d39a46fa5aba4838a23b9cc4e62"; };

  };

  class EvalResponse : public ros::Msg
  {
    public:
      bool success;

    EvalResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return EVAL; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class Eval {
    public:
    typedef EvalRequest Request;
    typedef EvalResponse Response;
  };

}
#endif
