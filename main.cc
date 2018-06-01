#include <gazebo/gazebo_client.hh>
#include <stdio.h>
#include "gazebo/gui/qt.h"
#include "ImageView.hh"
#include "TopicView.hh"
#include "ViewFactory.hh"

int main(int argc, char **argv)  
{
	if (argc == 1){
		std::cout << "You must specify the ImageStamped topic as an argument\n";
		return 0;
	} 	


	
	gazebo::client::setup(argc, argv);
	QApplication app(argc, argv);

	QWidget window;
	window.resize(100, 100);
	std::cout << "Creating window\n";
	std::string msgType = "gazebo.msgs.ImageStamped";
	std::string topic = argv[1];//"/gazebo/default/iris_demo/iris_demo/gimbal_2d/tilt_link/camera/image";
	//gazebo::gui::ImageView mainView(&window);
	//
	gazebo::gui::ViewFactory::RegisterAll();
	gazebo::gui::TopicView *view = gazebo::gui::ViewFactory::NewView(msgType, topic, &window);
	if (view)
		view->show();
	else
		std::cout << "Unable to create viewer for message type[" << msgType << "]\n";
	window.show();

	//while (true)
	//	gazebo::common::Time::MSleep(10);

	std::cout << "Shutingdown\n";
	return app.exec();

}
