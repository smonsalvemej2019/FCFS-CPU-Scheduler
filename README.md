# FCFS-CPU-Scheduler
<h1>Updates by date</h1> 
<hr>
<h2>03/4/21</h2>
<p>I decided to turn the code I had for single linked list using object-oriented programming</p> 
<p>into code for double linked list data structures. My plan is to implement 2 (maybe 3 queues)</p>
<ul>
	<li>A waiting queue.</li>
	<li>An I/O queue.</li>
	<li>A CPU queue.</li>
</ul>
<p>I might use loops to update the data inside each node</p>
<h3>ABOUT DATA</h3>
<p>The data given to me is in the form of an integer array for each process in the form CPU burst, I/O time, CPU burst, I/O time etc.</p> 
<p>The simulation needs to calculate waiting time(WT), response time(RT), and turnaround time(TT).</p>
<p>So far the data I need in the node structure is the following.</p>
<ul>
	<li>Array data – Will use pointers to pass the arrays</li>
	<li>Array counter – An integer will do. Array counters will be different for each process</li>
	<li>Global counter – This will represent a single time quanta. It is related to RT WT and TT.</li>
	<li>The global counter might be outside the class.</li>
</ul>
<hr>
<h2>03/5/21</h2>
<pre>I have made some test with the array data. My goal this time was to have a global counter that will simulate the CPU clock, and an internal counter that will manage the position of the array. My desired output was the following:</pre>
<ul>
<li>Data in array A[n] = t and the output would be t, t-1, t-2, … , t – t + 1 such that t > 0 and sizeof(A[n]) ≥ n ≥ 0.</li> 
<li>The global counter S such that S = A[0] + A[1] + A[2] + … + A[n] (the size of the outputted string)</li>
</ul>
<pre> For example. If my array is {3,2,1} my output is the following: 321211 And 6.
for more detail on the code please go to repo\code-snipets\3-5-21Update.txt
</pre>
 
