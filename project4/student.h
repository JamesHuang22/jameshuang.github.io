#define NAME_LEN 40

typedef struct {
  char name[NAME_LEN];
  unsigned int id;
  float shoe_size;
} Student;

Student new_student(const char name[], unsigned int id, float shoe_size);
void init_student(Student *const student, const char name[], unsigned int id,
                  float shoe_size);
unsigned int has_id(Student student, unsigned int id);
int has_name(Student student, const char name[]);
unsigned int get_id(Student student);
float get_shoe_size(Student student);
Student change_shoe_size(Student student, float new_shoe_size);
void change_name(Student *const student, const char new_name[]);
