//#include<string>
//#include<vector>
//#include <gst/gst.h>
//#include<iostream>
//
//using namespace std;
//
//typedef struct _CustomData {
//	GstElement *pipeline;
//	GstElement *source,*decodebin;
//	GstElement *convert,*vconvert;
//	GstElement *resample,*vsample;
//	GstElement *sink,*vsink;
//} CustomData;
//
//static void pad_added_handler(GstElement *src, GstPad *new_pad,CustomData *data) {
//	GstPad *sink_pad = gst_element_get_static_pad(data->vconvert, "sink");
//	gst_pad_link(new_pad, sink_pad);
//}
//
//void perform_flush(GstElement* pipeline, GstElement* source, const vector<string> &path, int k){
//	//g_print("inside");
//	g_print("playing state");
//	gst_element_set_state(pipeline, GST_STATE_PLAYING);
//	g_print("paused state");
////	gst_element_set_state(pipeline, GST_STATE_PAUSED);
//	GstEvent *flush_start = gst_event_new_flush_start();
//	gst_element_send_event(pipeline,flush_start);
//	gst_element_set_state(pipeline, GST_STATE_NULL);
//	GstEvent *flush_stop = gst_event_new_flush_stop(true);
//	gst_element_send_event(pipeline,flush_stop);
////	gst_element_set_state(pipeline, GST_STATE_PAUSED);
//	g_object_set(source, "location",path[k+1].c_str(),NULL);
//	gst_element_set_state(pipeline, GST_STATE_PLAYING);
//
//}
//
//int main (int argc, char ** argv)
//{
//	//gint64 k=0;
//  GstMessage *msg;
//  GstBus* bus;
//  GstStateChangeReturn ret;
//  CustomData data;
//
//  gst_init (&argc, &argv);
//
//  string path = "/home/ee213085/Videos/"; // Replace with the actual path to your directory
//     vector<string> videos;
//     vector<gchar*> result;
//     DIR *dir;
//     struct dirent *ent;
//
//     if ((dir = opendir(path.c_str())) != NULL) {
//    	 while ((ent = readdir(dir)) != NULL) {
//    		 std::string filename = ent->d_name;
//    		 if (filename.find_last_of(".") != std::string::npos) {
//    			 std::string extension = filename.substr(filename.find_last_of("."));
//    			 if (extension == ".mp4") {
//    				 videos.push_back(path+filename);
//    			 }
//    		 }
//    	 }
//         closedir(dir);
//     }
//
//
//     gst_init(&argc, &argv);
//
//     for(size_t k=0; k < videos.size(); k++){
//    	 cout << videos[k] << endl;
//    	 data.pipeline = gst_pipeline_new("test-pipeline");
//    	 data.source = gst_element_factory_make("filesrc", "source");
//    	 data.decodebin = gst_element_factory_make("decodebin", "source1");
//    	 data.vconvert = gst_element_factory_make("videoconvert", "vconvert");
//    	 data.vsample = gst_element_factory_make("videoscale", "sample");
//    	 data.vsink = gst_element_factory_make("autovideosink", "sink");
//
//    	 if (!data.pipeline || !data.source || !data.decodebin|| !data.vconvert|| !data.vsample || !data.vsink) {
//    		 g_printerr("Not all elements could be created for video.\n");
//    		 return -1;
//    	 }
//
//    	 gst_bin_add_many(GST_BIN(data.pipeline), data.source,data.decodebin, data.vconvert,data.vsample, data.vsink, NULL);
//
//     	gst_element_link(data.source,data.decodebin);
//     	if (!gst_element_link_many(data.vconvert,data.vsample,  data.vsink, NULL)) {
//     		g_printerr("Elements could not be linked.\n");
//     		gst_object_unref(data.pipeline);
//     		return -1;
//     	}
//
//
//     	g_object_set(data.source, "location",videos[k].c_str(),NULL);
//
//     	g_signal_connect(data.decodebin, "pad-added", G_CALLBACK (pad_added_handler),
//     					&data);
//
//     	ret = gst_element_set_state(data.pipeline, GST_STATE_PLAYING);
//     	if (ret == GST_STATE_CHANGE_FAILURE) {
//     		g_printerr("Unable to set the   to the playing state.\n");
//     		gst_object_unref(data.pipeline);
//     		return -1;
//     	}
//
//
//
//        //ret = gst_element_set_state(data.pipeline, GST_STATE_PAUSED);
//     	perform_flush(data.pipeline,data.source,videos,k);
//
//
//     	bus = gst_element_get_bus(data.pipeline);
//
//     	msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, (GstMessageType)(GST_MESSAGE_EOS));
//     	if (GST_MESSAGE_TYPE(msg) == GST_MESSAGE_EOS) {
//     		g_print("EOS");
//     		gst_element_set_state(data.pipeline, GST_STATE_NULL);
//     	}
//     }
//}
//
