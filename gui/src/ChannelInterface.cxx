////////////////////////////////////////////////////////////////////////////////
///ChannelInterface.cxx
///
///Provides formatting and display of NCO and Phase information for each channel
///
///Author: Ryan Seal
///Modified: 08/06/08
////////////////////////////////////////////////////////////////////////////////
#include "../include/ChannelInterface.h"

///Constructor
ChannelInterface::ChannelInterface(UsrpConfigStruct& usrpConfigStruct,
				   int x, int y, int width, int height, 
				   const char* label): 
    CustomTab(x,y,width,height,label), usrpConfigStruct_(usrpConfigStruct)
{
    colorVector_.push_back(fl_rgb_color(230,230,230));
    colorVector_.push_back(fl_rgb_color(100,100,100));

    for(int i=0; i<4; ++i){
	string str = "Channel ";
	str += lexical_cast<string>(i+1);
	ChannelGroupPtr ptr(new ChannelGroup(i,x+15,y+20,230,100,""));
	ptr->copy_label(str.c_str());
	ptr->callback(ChannelInterface::Update,&usrpConfigStruct_);
	channelArray_.push_back(ptr);
	this->add(channelArray_[i].get());
    }
    this->end();
};

