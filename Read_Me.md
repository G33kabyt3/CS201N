<<<<<<< HEAD
<<<<<<< HEAD
Video Demonstration: https://youtu.be/Q-ONuWzD3_A

=======
Video at: https://youtu.be/Q-ONuWzD3_A

The first part is all you need to watch to learn how to use it. The second part is just showing the program works under various circumstances. You should be able to stop watching at around 9 minutes.
>>>>>>> 73107b94c64b23a90da273bb03392f43ca970332
=======
Video at: https://youtu.be/Q-ONuWzD3_A

The first part is all you need to watch to learn how to use it. The second part is just showing the program works under various circumstances. You should be able to stop watching at around 9 minutes.
>>>>>>> refs/remotes/origin/master
Greetings! I'm the creator of this application, Timothy Ross. Here's how you get it to work!

If these steps are not done correctly, I can make no guarantee that the program will run. 
First off, download this file: 
https://datasets.imdbws.com/title.basics.tsv.gz
This is the whole dataset. 

Next, search it for all movies and save it as a file named MovieInfo. 
You can do this by using typing the command:

grep '	movie	' $$$ > MovieInfo.txt

into the terminal where $$$ is the path to wherever you chose to save the whole dataset.

Now a file named MovieInfo.txt will be saved in your home directory.

Keep track of this, you'll need it for later.
Next, build the program by navigating to the folder in which you have the program files on your terminal and typing in:

make CS201

This should create an executable in your directory which runs the program. If it doesn't, check to see that you have a C compiler installed. 

Now, run the program once to generate the files in your directory, place MovieInfo.txt into the directory MovieData.

Now run the program again!

Now you can follow the on screen prompts to run the program.

At the start, you have to log in a user in order to start modifying catalogs.
So, the first thing you should do is create a user by typing the number listed on the screen. You should be able to use a 50 character username. 
Now log in, following the on screen prompts. You can also delete this user later if you want. You must log into a file ending in .log

Next, you are sent to the main menu, where you can conduct a variety of operations on the catalog like add, delete, display and edit. Whenever you add, delete, or edit, you need to conduct a search based on a string you type in. Select the results of the search by typing in the number on the far left of the entry. 

In order for your changes to be saved, you need to log out the user. This will save all changes to the user file. After you log out, you will be sent back to the log in prompt, where you can either log in again, create a new user, delete the user you made, or exit the program by typing $exit. 


If you have any questions, email me at TBRoss1@crimson.ua.edu, and I would be happy to answer them. 

One more things:

If you simply hit return during the prompt for delete title, the whole catalog should be displayed. This was disable for add as printing the entire movie database takes a VERY long time. However, I kept it in delete as it is quite useful in that function. It's not a bug it's a feature, you know?


