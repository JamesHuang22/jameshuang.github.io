typedef struct {
  char *name;
  unsigned int id;
  float shoe_size;
} Student;

Student *new_student(const char name[], unsigned int id, float shoe_size);
unsigned int has_id(Student *const student, unsigned int id);
int has_name(Student *const student, const char name[]);
unsigned int get_id(Student *const student);
float get_shoe_size(Student *const student);
void change_shoe_size(Student *const student, float new_shoe_size);
void change_name(Student *const student, const char new_name[]);
void copy_student(Student *student1, Student *const student2);