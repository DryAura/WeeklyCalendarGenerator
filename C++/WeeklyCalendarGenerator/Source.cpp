#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <filesystem>

using namespace std;
namespace fs = std::experimental::filesystem;

class JsonParser//if you want to make a preset
{
public:
	//json stuff
	vector<string> keys;
	vector<string> values;
	vector<vector<string>> arrayValues;
	void Parse(string fileName)
	{
		bool buildKey = false;
		bool buildValue = false;
		bool inString = false;
		bool inArray = false;
		bool stringInArray = false;
		vector<string> blank;
		int keySoFar = -1;
		char c = ' ';
		string temp = "";
		ifstream read;
		read.open(fileName);
		while (read.get(c))
		{
			if (buildValue)
			{
				buildKey = false;
				if (inString)
				{
					if (c == '\"')
					{
						inString = false;
					}
					temp += c;
				}
				else if (inArray)
				{
					if (stringInArray)
					{
						if (c == '\"')
						{
							stringInArray = false;
						}
						temp += c;
					}
					else
					{
						if (c != ' ' && c != ':' && c != ',' && c != '}' && c != '\n' && c != ']')
						{
							if (c == '\"')
							{
								stringInArray = true;
								temp += c;
							}
							else
							{
								temp += c;
							}
						}
						else if (c == ',' || c == '}' || c == '\n' || c == ']')
						{
							arrayValues[keySoFar].push_back(temp);
							temp = "";
							if (c == ']')
							{
								inArray = false;
								buildValue = false;
							}
						}
					}
				}
				else
				{
					if (c != ' ' && c != ':' && c != ',' && c != '}' && c != '\n')
					{
						if (c == '\"')
						{
							inString = true;
							temp += c;
						}
						else if (c == '[')
						{
							inArray = true;
						}
						else
						{
							temp += c;
						}
					}
					else if (c == ',' || c == '}' || c == '\n')
					{
						buildValue = false;
						values.push_back(temp);
						temp = "";
					}
				}
			}
			else
			{
				if (c == '\"')
				{
					if (buildKey)
					{
						buildValue = true;
						keys.push_back(temp);
						arrayValues.push_back(blank);
						keySoFar++;
						temp = "";
					}
					buildKey = true;
				}
				else if (buildKey)
				{
					temp += c;
				}
			}
		}
		read.close();
	}
	void clearParser()
	{
		keys.clear();
		values.clear();
		arrayValues.clear();
	}
	int getValuePosition(string key)
	{
		int toReturn = -1;
		bool found = false;
		for (int i = 0; i < keys.size(); i++)
		{
			if (values[i] == key)
			{
				found = true;
			}
			if (!found)
			{
				toReturn++;
			}
		}
		return toReturn;
	}
	string removeQuotationMarks(string in)
	{
		in.erase(in.begin(), in.begin() + 1);
		in.erase(in.end() - 1, in.end());
		return in;
	}
};

struct WeekItems
{
	vector<string> MondayItems;
	vector<string> TuesdayItems;
	vector<string> WednesdayItems;
	vector<string> ThursdayItems;
	vector<string> FridayItems;
	vector<string> SaturdayItems;
	vector<string> SundayItems;
	vector<string> MiscItems;
};
class HtmlGenerator
{
	WeekItems w;
public:
	void GetWeeklyItems()
	{
		string userResponse = "";
		//monday
		while (userResponse != "X" && userResponse != "x")
		{
			system("cls");
			cout << "Enter Item for Monday (enter 'x' to go to the next day):" << endl << endl;
			getline(cin, userResponse);
			if (userResponse != "X" && userResponse != "x")
			{
				w.MondayItems.push_back(userResponse);
			}
		}
		userResponse = "";
		//Tuesday
		while (userResponse != "X" && userResponse != "x")
		{
			system("cls");
			cout << "Enter Item for Tuesday (enter 'x' to go to the next day):" << endl << endl;
			getline(cin, userResponse);
			if (userResponse != "X" && userResponse != "x")
			{
				w.TuesdayItems.push_back(userResponse);
			}
		}
		userResponse = "";
		//Wednesday
		while (userResponse != "X" && userResponse != "x")
		{
			system("cls");
			cout << "Enter Item for Wednesday (enter 'x' to go to the next day):" << endl << endl;
			getline(cin, userResponse);
			if (userResponse != "X" && userResponse != "x")
			{
				w.WednesdayItems.push_back(userResponse);
			}
		}
		userResponse = "";
		//Thursday
		while (userResponse != "X" && userResponse != "x")
		{
			system("cls");
			cout << "Enter Item for Thursday (enter 'x' to go to the next day):" << endl << endl;
			getline(cin, userResponse);
			if (userResponse != "X" && userResponse != "x")
			{
				w.ThursdayItems.push_back(userResponse);
			}
		}
		userResponse = "";
		//Friday
		while (userResponse != "X" && userResponse != "x")
		{
			system("cls");
			cout << "Enter Item for Friday (enter 'x' to go to the next day):" << endl << endl;
			getline(cin, userResponse);
			if (userResponse != "X" && userResponse != "x")
			{
				w.FridayItems.push_back(userResponse);
			}
		}
		userResponse = "";
		//Saturday
		while (userResponse != "X" && userResponse != "x")
		{
			system("cls");
			cout << "Enter Item for Saturday (enter 'x' to go to the next day):" << endl << endl;
			getline(cin, userResponse);
			if (userResponse != "X" && userResponse != "x")
			{
				w.SaturdayItems.push_back(userResponse);
			}
		}
		userResponse = "";
		//Sunday
		while (userResponse != "X" && userResponse != "x")
		{
			system("cls");
			cout << "Enter Item for Sunday (enter 'x' to go to the next day):" << endl << endl;
			getline(cin, userResponse);
			if (userResponse != "X" && userResponse != "x")
			{
				w.SundayItems.push_back(userResponse);
			}
		}
		userResponse = "";
		//misc
		while (userResponse != "X" && userResponse != "x")
		{
			system("cls");
			cout << "Enter misc weekly Item (enter 'x' to complete weekly calendar):" << endl << endl;
			getline(cin, userResponse);
			if (userResponse != "X" && userResponse != "x")
			{
				w.MiscItems.push_back(userResponse);
			}
		}
	}

	string GenerateHtmlCode()
	{
		string htmlCode = "";

		htmlCode += "<!DOCTYPE html>";
		htmlCode += "\n";
		htmlCode += "<html>";
		htmlCode += "\n";
		htmlCode += "<head>";
		htmlCode += "\n";
		htmlCode += "<link rel=\"stylesheet\" href=\"style.css\">";
		htmlCode += "\n";
		htmlCode += "<link rel=\"icon\" href=\"res/websiteDesign/fav.png\">";
		htmlCode += "\n";
		htmlCode += "<title>Weekly Calendar</title>";
		htmlCode += "\n";
		htmlCode += "</head>";
		htmlCode += "\n";
		htmlCode += "<body>";
		htmlCode += "\n";
		htmlCode += "<table id=\"tableMain\">";
		htmlCode += "\n";
		htmlCode += "<tr>";
		htmlCode += "\n";
		htmlCode += "<th> </th>";
		htmlCode += "\n";
		htmlCode += "<th> </th>";
		htmlCode += "\n";
		htmlCode += "<th> </th>";
		htmlCode += "\n";
		htmlCode += "<th> </th>";
		htmlCode += "\n";
		htmlCode += "</tr>";
		htmlCode += "\n";
		htmlCode += "<tr>";
		htmlCode += "\n";
		htmlCode += "<td colspan=\"4\"> <h1 id=\"TitleSpot\">Weekly Calendar</h1> </td>";
		htmlCode += "\n";
		htmlCode += "</tr>";
		htmlCode += "\n";
		htmlCode += "<tr>";
		htmlCode += "\n";
		htmlCode += "<td> <h2>Monday</h2> </td>";
		htmlCode += "\n";
		htmlCode += "<td> <h2>Tuesday</h2> </td>";
		htmlCode += "\n";
		htmlCode += "<td> <h2>Wednesday</h2> </td>";
		htmlCode += "\n";
		htmlCode += "<td> <h2>Thursday</h2> </td>";
		htmlCode += "\n";
		htmlCode += "</tr>";
		htmlCode += "\n";
		htmlCode += "<tr>";
		htmlCode += "\n";
		//Monday
		htmlCode += "<td> <h3>";
		//activities go here
		for (int i = 0; i < w.MondayItems.size(); i++)
		{
			htmlCode += "+ ";
			htmlCode += w.MondayItems[i];
			if (i != w.MondayItems.size())
			{
				htmlCode += "<br>";
			}
		}
		htmlCode += "</h3> </td>";
		htmlCode += "\n";
		//Tuesday
		htmlCode += "<td> <h3>";
		//activities go here
		for (int i = 0; i < w.TuesdayItems.size(); i++)
		{
			htmlCode += "+ ";
			htmlCode += w.TuesdayItems[i];
			if (i != w.TuesdayItems.size())
			{
				htmlCode += "<br>";
			}
		}
		htmlCode += "</h3> </td>";
		htmlCode += "\n";
		//Wednsday
		htmlCode += "<td> <h3>";
		//activities go here
		for (int i = 0; i < w.WednesdayItems.size(); i++)
		{
			htmlCode += "+ ";
			htmlCode += w.WednesdayItems[i];
			if (i != w.WednesdayItems.size())
			{
				htmlCode += "<br>";
			}
		}
		htmlCode += "</h3> </td>";
		htmlCode += "\n";
		//Thursday
		htmlCode += "<td> <h3>";
		//activities go here
		for (int i = 0; i < w.ThursdayItems.size(); i++)
		{
			htmlCode += "+ ";
			htmlCode += w.ThursdayItems[i];
			if (i != w.ThursdayItems.size())
			{
				htmlCode += "<br>";
			}
		}
		htmlCode += "</h3> </td>";
		htmlCode += "\n";
		htmlCode += "<tr>";
		htmlCode += "\n";
		htmlCode += "<td> <h2>Friday</h2> </td>";
		htmlCode += "\n";
		htmlCode += "<td> <h2>Saturday</h2> </td>";
		htmlCode += "\n";
		htmlCode += "<td> <h2>Sunday</h2> </td>";
		htmlCode += "\n";
		htmlCode += "<td> <h2>Misc.</h2> </td>";
		htmlCode += "\n";
		htmlCode += "</tr>";
		htmlCode += "\n";
		htmlCode += "<tr>";
		htmlCode += "\n";
		//Friday
		htmlCode += "<td> <h3>";
		//activities go here
		for (int i = 0; i < w.FridayItems.size(); i++)
		{
			htmlCode += "+ ";
			htmlCode += w.FridayItems[i];
			if (i != w.FridayItems.size())
			{
				htmlCode += "<br>";
			}
		}
		htmlCode += "</h3> </td>";
		htmlCode += "\n";
		//Saturday
		htmlCode += "<td> <h3>";
		//activities go here
		for (int i = 0; i < w.SaturdayItems.size(); i++)
		{
			htmlCode += "+ ";
			htmlCode += w.SaturdayItems[i];
			if (i != w.SaturdayItems.size())
			{
				htmlCode += "<br>";
			}
		}
		htmlCode += "</h3> </td>";
		htmlCode += "\n";
		//Sunday
		htmlCode += "<td> <h3>";
		//activities go here
		for (int i = 0; i < w.SundayItems.size(); i++)
		{
			htmlCode += "+ ";
			htmlCode += w.SundayItems[i];
			if (i != w.SundayItems.size())
			{
				htmlCode += "<br>";
			}
		}
		htmlCode += "</h3> </td>";
		htmlCode += "\n";
		//misc
		htmlCode += "<td> <h3>";
		//activities go here
		for (int i = 0; i < w.MiscItems.size(); i++)
		{
			htmlCode += "+ ";
			htmlCode += w.MiscItems[i];
			if (i != w.MiscItems.size())
			{
				htmlCode += "<br>";
			}
		}
		htmlCode += "</h3> </td>";
		htmlCode += "\n";
		htmlCode += "</tr>";
		htmlCode += "\n";
		htmlCode += "</table>";
		htmlCode += "\n";
		htmlCode += "</body>";
		htmlCode += "\n";
		htmlCode += "</html>";
		return htmlCode;
	}
	void CreateHtmFile()
	{
		try
		{
			remove("WeeklyCalendar.htm");
		}
		catch(...)
		{
			string doNothing;
		}
		string htmlCode = GenerateHtmlCode();
		ofstream out("WeeklyCalendar.htm");
		out << htmlCode;
		out.close();
	}
};

int main()
{
	HtmlGenerator App;
	App.GetWeeklyItems();
	App.CreateHtmFile();
	return 0;
}