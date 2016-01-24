// Done by
// Nada Abdul Majeed Pulath - coe12b015
// Anusha - edm12b031
// Sravana - edm12b014

Final.ino - contains the arduino code to use the Fingerprint module.
admin folder -  contains the php files for the admin page that helps to manage attendance, OD and MC approve requests.
student folder - contains the php files for the student page that helps him/her to view his course-wise attendance and request for OD or/and MC.
attendance.sql - contains all the sql tables

Description of files in 'admin' folder

login.php - Logins to the admin page
logout.php - Logout from the admin page
chg_pass.php - Change password
admin.php - home page for admin page
mainmenu_admin.php - All the succeeding php files contain this file.	
approve_MC.php - Displays all the MC requests. Admin can approve or decline the requests.
approve_OD.php - Displays all the OC requests. Admin can approve or decline the requests.
update_attendance.php - Updates attendance by reading contents from the file named by the course (Eg: 'ELE_401.txt').Note: The file 'ELE_401.txt' contains the output from the arduino. It stores the attendance in the  below format:  
	Date:
	1/0
	1/0
	...
	...
	...
	1/0
	Date:
	1/0
	1/0
	...
	...
	...
	1/0
	Date:
	1/0
	1/0
	...
	...
	...
	1/0
	//End of file 
	The number of lines between any two dates is equal to the number of enrolled students in the device. 1 - Present, 0 - Abcent.
view_attendance.php - the succeeding php files contain this file.
viewby_all.php - view attendance summary of all students
viewby_date.php - view attendance by date
viewby_student.php - view attendance by rollno


Description of files in 'student' folder


chg_pass.php - Change password
home.php - Student home page
login.php - Login to student page
logout.php - Logout from the student page
mainmenu.php - All succeeding php files in the list contain this file.
my_MC_submissions.php - Make MC requests
my_OD_requests.php - Make OD requests
my_attendance.php - Takes to View attendance page
my_courses.php - Shows all the courses enrolled
my_viewby.php - All the succeeding php files in the list contains this file
my_viewby_course.php - View attendance my course
my_viewby_date.php - View attendance by date
my_viewby_summary.php - View attendance by summary


