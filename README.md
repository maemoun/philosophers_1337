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

Concept :        Explanation.
Thread :        Each philosopher runs as a separate thread doing a routine: think → pick up forks → eat → sleep.
Mutex (pthread_mutex) :        Used to prevent race conditions when philosophers pick up or put down forks.
Deadlock :        Situation where all philosophers pick up one fork and wait forever for the second one. You must avoid this.
Starvation :        A philosopher never gets to eat. Must be avoided by ensuring fairness.
Time management :        You'll need to handle timing precisely (how long to eat, sleep, die without eating, etc.).

_______________________________________________
🛠️ Common Project Structure:
_______________________________________________

--->	"philo.h"
   	Header file with:

 ->structs for philosopher and table.

 ->function prototypes.

 ->constants (like t_die, t_eat, etc.).

--->	"philo.c"

   * Main file:

        -> parses arguments.

        -> sets up philosophers and threads.

        -> launches the simulation.

--->	"ft_philo_routine.c"

* The routine each philosopher thread runs:

		void *philo_routine(void *arg)
       	 {
	        	while (true)
	       	 {
		      	  take_forks();
		     	   eat();
				put_down_forks();
				sleep();
				think();
			}
		}

--->	"ft_time.c"

   * Handles:

-> getting current timestamp.

->sleeping precisely.

 ---> "ft_check_die.c" :
 
* A monitor thread or loop that watches if any philosopher hasn't eaten in time and dies.

 _____________________________________________
 📋 Typical Input:
 _____________________________________________

	./philo number_of_philos time_to_die time_to_eat time_to_sleep [number_of_times_each_philo_must_eat]

Example:

	./philo 5 800 200 200
 
 --->	This means:

 * 5 philosophers.

 * die after 800 ms without eating.

 * eat for 200 ms.

 * sleep for 200 ms.
 
______________________________________________
⚠️ Challenges to Solve :
______________________________________________

Problem :	Solution.
Deadlock :	Use an odd-even strategy or always pick up the lowest-numbered fork first.
Accurate timing :	Use gettimeofday or clock_gettime for precise time, and usleep() for delay.
Race conditions :	Use pthread_mutex_lock/unlock to protect shared resources.

______________________________________________
✅ Success Criteria :
______________________________________________

* No philosopher should die (unless timing runs out).

* No race conditions.

* No deadlock.

* Correct and clean multithreaded behavior.

* Good memory management (no leaks).
