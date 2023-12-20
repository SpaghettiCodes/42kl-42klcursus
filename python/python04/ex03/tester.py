# from new_student import Student

# student = Student(name="Edward", surname="agle")
# print(student)

# # from new_student import Student

# # student = Student(name = "Edward", surname = "agle", id = "toto")
# # print(student)

from new_student import Student

student = Student(name="Edmund", surname="agle")
print(student)
print("------")

# will crash

student = Student(name="Edward", surname="agle", login="pigeon")
print(student)
