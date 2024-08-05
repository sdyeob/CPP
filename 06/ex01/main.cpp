
# include <unistd.h>
# include <sys/wait.h>
# include "Data.hpp"
# include "Serializer.hpp"

int main(void)
{
    struct Data* data_for_serialization = new (struct Data);
    data_for_serialization->variable = 42;

    std::cout << "======PARANT PROCESS======" << std::endl;
    std::cout << "Data : " << data_for_serialization->variable << std::endl;
    std::cout << "Address : " << data_for_serialization << std::endl;

    uintptr_t serialized_data = Serializer::serialize(data_for_serialization);

    pid_t pid = fork();

    if (pid == 0)
    {
        Data* deserialized_ptr = Serializer::deserialize(serialized_data);
        std::cout << "======CHILD PROCESS=======" << std::endl;
        std::cout << "Data : " << deserialized_ptr->variable << std::endl;
        std::cout << "Address : " << deserialized_ptr << std::endl;
        std::cout << "==========================" << std::endl;
    }

    if (waitpid(pid, NULL, 0) == pid) std::cout << "ALL SESSION IS ENDED" << std::endl;

    delete data_for_serialization;
    return (0);
}
