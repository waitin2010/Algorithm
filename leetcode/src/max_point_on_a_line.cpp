#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;




/* Definition for a point.
 */
struct Point {
     int x;
      int y;
     Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
 };

struct Line {
	Point a;
	Point b;
	Line():a(),b(){}
	Line(Point x, Point y):a(x.x, x.y), b(y.x, y.y){}
};
bool point_in_line(Point &point, Line &line){
	int left = (point.x - line.a.x)*(line.b.y-line.a.y);
	int right =(point.y - line.a.y)*(line.b.x-line.a.x);

	return left==right;
}
/// if point in the line, return which line that point on.
bool is_point_in_lines(Point &point, vector<Line> &line, vector<int> &which_line){
	for(int i=0;i<line.size();i++){
		if(point_in_line(point, line[i])) {
			which_line.push_back(i);
		}
	}
	return which_line.size()>0?true:false;
}
/// add 1 to the correspond line
void add_correspond_line_one_point(map<int, int> &line_point_number, vector<int> which_line){

		for(int i=0;i<which_line.size();i++)
			line_point_number[which_line[i]]++;
}
bool is_same_line(Line line1, Line line2){
	if(point_in_line(line1.a,line2)&&point_in_line(line1.b, line2)) return true;
	else return false;
}
/// construct new k= pre_count lines
void construct_new_k_line(vector<Point> &points, int end,vector<Line> &pre_line,map<int, int> &line_point_number){
	if(points.size()<=1|| end <1) return ;
	Point start = points[end];
	for(int i=0;i<end;i++){
		Point end = points[i];
		Line new_line = Line(start, end);
		int  j;
		for(j=0;j<pre_line.size();j++){
			if(is_same_line(new_line, pre_line[j])) break;
		}
		if(j>=pre_line.size()){
			pre_line.push_back(new_line);
			line_point_number.insert(make_pair(pre_line.size()-1,2));
		}else{
			line_point_number[j]++;
		}
	}
}
int max_point_line(map<int, int> line_point_number){
	if(line_point_number.size()<=0) return -1;
	int max = line_point_number[0];
	for(int i=1;i<line_point_number.size();i++){
		max = max > line_point_number[i]?max: line_point_number[i];
	}
	return max;
}
 int maxPoints(vector<Point> &points) {
	 struct {  
            bool operator()(Point a, Point b)  
            {     
                return a.x < b.x;  
            }     
        } customLess;  
     sort(points.begin(),points.end(),customLess); 
	 int size = points.size();/// the number of test points
	 if(size <=2) return size;
	 vector<Line> pre_lines;
	 vector<int> which_line;
	 map<int, int> line_point_number;
	 for(int i=0;i<size;i++){
		 /// if ith point in the previous lines, add one to that lines' point number
		 which_line.clear();
		 if(is_point_in_lines(points[i],pre_lines,which_line))
			 add_correspond_line_one_point(line_point_number,which_line);
		 else/// else construct new lines to pre_lines
			 construct_new_k_line(points, i, pre_lines,line_point_number);
	 }
	 return max_point_line(line_point_number);
 }
 /*
 (0,0),(1,1),(1,-1)
 */
int main(){
	vector<Point> points;
	/*for(int i=0;i<10;i++){
		Point temp_point = Point(i,i+1);
		points.push_back(temp_point);
	}
	for(int i=0;i<5;i++){
		Point temp_point = Point(i+1, i+1);
		points.push_back(temp_point);
	}*/
	points.push_back(Point(0,1));
	points.push_back(Point(1,0));
	points.push_back(Point(-1,0));
	points.push_back(Point(2,-1));
	points.push_back(Point(-2,-1));
	points.push_back(Point(3,0));
	points.push_back(Point(4,0));
	points.push_back(Point(1,0));
	cout<<maxPoints(points);
	return 0;
}
