g++ -I. main.cpp User.cpp Roles/Admin.cpp Roles/Customer.cpp Account.cpp Bank.cpp -o BankApp
if ($?) {
    .\BankApp
}
