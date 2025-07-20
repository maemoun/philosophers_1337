_______________________________________________
📋 PHILOSOPHERS:
_______________________________________________

The Philosophers project is a classic concurrency and synchronization problem used in computer science, and it's commonly assigned in schools like 42/1337 to teach multithreading, mutexes, and deadlock prevention.

_______________________________________________
🔧 Your Goal in the Project:
_______________________________________________

You must simulate this behavior using:

    *Threads (each philosopher is a thread)

    *Mutexes (to protect the forks — shared resources)

_______________________________________________
⚙️ Key Concepts to Implement:
_______________________________________________

Concept :        Explanation
Thread :        Each philosopher runs as a separate thread doing a routine: think → pick up forks → eat → sleep
Mutex (pthread_mutex) :        Used to prevent race conditions when philosophers pick up or put down forks
Deadlock :        Situation where all philosophers pick up one fork and wait forever for the second one. You must avoid this.
Starvation :        A philosopher never gets to eat. Must be avoided by ensuring fairness.
Time management :        You'll need to handle timing precisely (how long to eat, sleep, die without eating, etc.)

_______________________________________________
🛠️ Common Project Structure:
_______________________________________________

"philo.h"
   Header file with:

        *structs for philosopher and table.

        *function prototypes.

        *constants (like t_die, t_eat, etc.).

--->	"philo.c"
   		Main file:

        *parses arguments.

        *sets up philosophers and threads.

        *launches the simulation.

--->	"ft_philo_routine.c"

	The routine each philosopher thread runs:

      //  void *philo_routine(void *arg)
        {
	        while (true)
	        {
		        take_forks();
		        eat();
			put_down_forks();
			sleep();
			think();
		}
	} //

--->	"ft_time.c"
   		Handles:

	*getting current timestamp.

	*sleeping precisely.

 ---> "ft_check_die.c" :
	A monitor thread or loop that watches if any philosopher hasn't eaten in time and dies.
