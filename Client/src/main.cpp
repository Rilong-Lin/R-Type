#include <iostream>
#include <Client.h>

int	main(int argc, char *argv[])
{
    Client client = Client();
    std::cout << "Client créer";
    client.init();
    std::cout << "Client init";
    client.run();
}