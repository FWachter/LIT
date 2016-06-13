#ifndef _ROS_SERVICE_GetPeerList_h
#define _ROS_SERVICE_GetPeerList_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rtt_ros_msgs
{

static const char GETPEERLIST[] = "rtt_ros_msgs/GetPeerList";

  class GetPeerListRequest : public ros::Msg
  {
    public:

    GetPeerListRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return GETPEERLIST; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetPeerListResponse : public ros::Msg
  {
    public:
      uint32_t peers_length;
      char* st_peers;
      char* * peers;

    GetPeerListResponse():
      peers_length(0), peers(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->peers_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->peers_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->peers_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->peers_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->peers_length);
      for( uint32_t i = 0; i < peers_length; i++){
      uint32_t length_peersi = strlen(this->peers[i]);
      memcpy(outbuffer + offset, &length_peersi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->peers[i], length_peersi);
      offset += length_peersi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t peers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      peers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      peers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      peers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->peers_length);
      if(peers_lengthT > peers_length)
        this->peers = (char**)realloc(this->peers, peers_lengthT * sizeof(char*));
      peers_length = peers_lengthT;
      for( uint32_t i = 0; i < peers_length; i++){
      uint32_t length_st_peers;
      memcpy(&length_st_peers, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_peers; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_peers-1]=0;
      this->st_peers = (char *)(inbuffer + offset-1);
      offset += length_st_peers;
        memcpy( &(this->peers[i]), &(this->st_peers), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return GETPEERLIST; };
    const char * getMD5(){ return "6db093f77b4f8d943666a07989041c39"; };

  };

  class GetPeerList {
    public:
    typedef GetPeerListRequest Request;
    typedef GetPeerListResponse Response;
  };

}
#endif
