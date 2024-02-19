# Weather-Analysis-Program
ELEC 1520 Final Project

**Objective:**
The objective of the final project is to develop a C++ program that can process daily weather data 
over the span of years and perform various analyses on the data such as average temperature or precipitation
over periods of time (perhaps, days, months, or years). The results of the analysis are to be exported to a data 
file that can be read in by utilities such as Matlab. The second objective is to write Matlab scripts that can read 
in these data files and plot the data analyzed in a meaningful way.

**Description:**

**Data:** You are given a large data set for analysis. For this term’s project, the data set is daily weather for Denver 
Colorado during the period of June 1908 through early November 2022. The data is included in the link for this 
project. The first line of the file contains the number of rows in the data set (41178 lines). The data set has 9 
columns. The columns are:

Month, Day, Year, precipitation(inches), snow(inches), snow depth(inches), max temp, min temp, Obs temp

The month, day and year are integer values. The remaining values are floating point numbers. The 
temperatures are in degrees Fahrenheit. The observed temperature is the temperature measured at 12 noon of 
that day.

**Analysis:** The code should be able to perform the following analyses:
1) Find the total precipitation per a given period of time – that is the total amount of rain that fell during 
that period of time
2) Find the total snowfall per a given period of time.
3) Find the maximum and/or minimum temperature over a given period of time
4) Find the average maximum and/or minimum temperature per given period of time
5) Find the average temperature at mid-day per given period of time.
   
The period of time can be per week, month, or year. The code should also be able to output, or tabulate, these 
averages for a broader period of time. For example, finding the average maximum monthly temperature over 
the period of 1908 to 2022. The table would then contain three columns: month, year and maximum average 
temperature. Another example would be to find the total rainfall per year over the period of 1908 to 2022. 
