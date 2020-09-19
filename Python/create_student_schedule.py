class StudentCourse:

    def __init__(self, studentInfo, courseInfo, semester, year, grade):
        self.studentInfo = studentInfo
        self.courseInfo = courseInfo
        self.semester = semester
        self.year = year
        self.grade = grade

    def __str__(self):
        return self.semester + ', ' + self.year

    def getSemester(self):
        return self.semester

    def getYear(self):
        return self.year

    def getGrade(self):
        return self.grade

class Student:

    def __init__(self, firstName, lastName, studentID):
        self.firstName = firstName
        self.lastName = lastName
        self.studentID = studentID

    def __str__(self):
        return self.firstName + ' ' + self.lastName + ' ' + self.studentID

    def getFirstName(self):
        return self.firstName

    def getLastName(self):
        return self.lastName

    def getStudentID(self):
        return self.studentID



class Course:

    def __init__(self, courseName, description, creditHours):
        self.courseName = courseName
        self.description = description
        self.creditHours = creditHours

    def __str__(self):
        return self.courseName + ', ' + self.description + ', ' + str(self.creditHours) + ' credit hours'

    def getCourseName(self):
        return self.courseName

    def getDescription(self):
        return self.description

    def getCreditHours(self):
        return self.creditHours


def main():

    courseList = []
    first = input("Enther student's first name: " )
    last = input("Enther student's last name: " )
    student_id = input("Enter student's ID: ")
    studentInfo = Student(first, last, student_id)

    semester = input('Enter semester: ')
    year = input('Enter year: ')
    courseName = input('Enter course name (X to stop): ')


    while (courseName != 'X'):
        description = input('Enter course description: ')
        creditHours = int(input('Enter credit hours: '))
        grade = input('Enter grade: ')
        courseInfo = Course(courseName, description, creditHours)
        courseList.append(courseInfo)
        courseName = input('Enter course name (X to stop): ')


        
    points = 0  
    gradeTotal = 0.0 
    creditTotal = 0.0
    i = 0

    for i in range(len(courseList)):
        creditTotal = creditTotal + creditHours
        if grade == 'A':
            points = 4
        elif grade == 'B':
            points = 3
        elif grade == 'C':
            points = 2
        elif grade == 'D':
            points = 1
        else:
            points = 0
        gradeTotal = gradeTotal + (points * creditHours)

    semesterInfo =StudentCourse(studentInfo, courseInfo, semester, year, grade)
    first = True
    for i in range(len(courseList)):
        if first:
            print(studentInfo)
            print(semesterInfo)
            print(courseList[i])
            first = False
        else:
            print(courseList[i])
    print('Total Credit Hours: ' + str(creditTotal))
    semesterGPA = gradeTotal / creditTotal
    print('Semester GPA is: ' + str(semesterGPA))

        
main()
        
    


        
