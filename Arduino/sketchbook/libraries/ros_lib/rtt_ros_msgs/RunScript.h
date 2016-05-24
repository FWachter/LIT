#ifndef _ROS_SERVICE_RunScript_h
#define _ROS_SERVICE_RunScript_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rtt_ros_msgs
{

static const char RUNSCRIPT[] = "rtt_ros_msgs/RunScript";

  class RunScriptRequest : public ros::Msg
  {
    public:
      const char* file_path;

    RunScriptRequest():
      file_path("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_file_path = strlen(this->file_path);
      memcpy(outbuffer + offset, &length_file_path, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->file_path, length_file_path);
      offset += length_file_path;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_file_path;
      memcpy(&length_file_path, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_file_path; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_file_path-1]=0;
      this->file_path = (char *)(inbuffer + offset-1);
      offset += length_file_path;
     return offset;
    }

    const char * getType(){ return RUNSCRIPT; };
    const char * getMD5(){ return "a1f82596372c52a517e1fe32d1e998e8"; };

  };

  class RunScriptResponse : public ros::Msg
  {
    public:
      bool success;

    RunScriptResponse():
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

    const char * getType(){ return RUNSCRIPT; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class RunScript {
    public:
    typedef RunScriptRequest Request;
    typedef RunScriptResponse Response;
  };

}
#endif
