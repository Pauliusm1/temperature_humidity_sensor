
/* Create two doubly linked lists to store periphery power modes:
    - One to store list of peripheries that needs mcu to be fully active
    - One to store list of peripheries that can put mcu to lower power mode (halt)
   If both linked lists are empty - but device to deep sleep */


void PwrAddActiveMode(void)
{
    // Add active mode user to doubly linked list
}

void PwrRemoveActiveMode(void)
{
    // Remove active mode user from doubly linked list
}

void PwrAddHaltMode(void)
{
    // Add halt mode user to doubly linked list
}

void PwrRemoveHaltMode(void)
{
    // Remove halt mode user from doubly linked list
}

void PwrManageSleep(void)
{
    // If any active mode user is active - return
    // If any halt mode user is active - put device to halt mode
    // If nor active, nor halt mode users are active - put device to deep sleep
}
