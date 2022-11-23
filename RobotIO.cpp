#include "RobotIO.h"

RobotIO::RobotIO(string filename)
{
	set_filename(filename);
}

// TaskList TaskIO::load_tasks()
// {
// 	TaskList tasks;
// 	TaskIO taskIO("taskList.txt");
// 	string line = "", description = "", task_complete = "";
// 	bool is_task_complete = "";
// 	ifstream input_file(taskIO.get_filename());
// 	//
// 	if (input_file)
// 	{
// 		while (getline(input_file, line, '\n'))
// 		{
// 			stringstream s(line);
// 			getline(s, description, ',');
// 			s >> task_complete;
// 			is_task_complete = task_complete == "true" ? true : false;
// 			Task task(description, is_task_complete);
// 			tasks += task;
// 		}
// 	}
// 	else {
// 		cout << "File not found" << endl;
// 	}
// 	input_file.close();
// 	return tasks;
// }

// void TaskIO::save_tasks(TaskList& tasks)
// {
// 	TaskIO taskIO("taskList.txt");
// 	ofstream output_file(taskIO.get_filename());
// 	for (int i = 0; i < tasks.length; i++)
// 	{
// 		string task_complete = tasks[i].get_task_complete() == true ? "true" : "false";
// 		output_file << tasks[i].get_description() << "," << task_complete << endl;
// 	}
// 	output_file.close();
// }

void RobotIO::set_filename(string fname_param)
{
	filename = fname_param;
}

string RobotIO::get_filename()
{
	return filename;
}
