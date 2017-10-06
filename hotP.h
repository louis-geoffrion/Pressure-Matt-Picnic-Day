

void hotP()
{
allzero();  //start frame

	    //turn off all leds
	    int j;
	    for(j=lednum;j>0;j--)
	    {
	    	off();
	    }

	    //start again
	    allzero();

	    //
	    while(SSIBusy(SSI0_BASE))
	    {
	    }


    while(1)
    {
    	static int rounds;
    	static int begin;
    	static int start;
    	start = 0;
    	rounds = 0;
    	while(rounds == 0)
    	{
    		rounds = rand() % 11;
    	}
    	begin = 0;
    	while (begin < rounds)
    	{
    		if (start == 0)
    		{
    			allzero();
    		    SysCtlDelay(4000000);
    		    int j;
    		    for (j=lednum; j>0; j--)
    		    {
    		    	off();
    		    }
    		    SysCtlDelay(4000000)
    		    allzero();
    		    for (j=lednum; j>0; j--)
    		    {
    		    	fullred();
    		    }
    		    start = 1;
    		 }
    		 if (start == 1)
    		 {
    			 allzero();
    			 SysCtlDelay(4000000);
    		     int j;
    		 	 for (j=lednum; j>0; j--)
    		     {
    		 		 off();
    		     }
    		 	 SysCtlDelay(4000000);
    		     allzero();
    		     for (j=lednum; j>0; j--)
    		     {
    		   		fullyellow();
    		     }
    		     start = 2;
    		 }
    		 static int randomPerson;
    		 randomPerson = 0;
    		 while (randomPerson == 0)
    		 {
    			 randomPerson = rand() % 5;
    		 }
    		 switch(randomPerson)
    		 {
    		 	 case 1:
    		 		 while (flag1 == 0)
    		 		 {
						allzero();
						SysCtlDelay(4000000);
						int j;
						for (j=lednum; j>0; j--)
						{
							off();
						}
						SysCtlDelay(4000000);
						allzero();
						for (j=lednum; j>0; j--)
						{
							fullred();
						}
    		 		 }
    		 	 case 2:
    		 		 while(flag2 == 0)
    		 		 {
						 allzero();
						 SysCtlDelay(4000000);
						 int j;
						 for (j=lednum; j>0; j--)
						 {
							 off();
						 }
						 SysCtlDelay(4000000);
						 allzero();
						for (j=lednum; j>0; j--)
						{
							fullblue();
						}
    		 		 }
    		 	 case 3:
    		 		 while (flag3 == 0)
    		 		 {
						 allzero();
						 SysCtlDelay(4000000);
						 int j;
						 for (j=lednum; j>0; j--)
						 {
							 off();
						 }
						 SysCtlDelay(4000000);
						 allzero();
						 for (j=lednum; j>0; j--)
						 {
							fullgreen();
						 }
    		 		 }
    		 	 case 4:
    		 		 while (flag 4 == 0)
    		 		 {
						 allzero();
						 SysCtlDelay(4000000);
						 int j;
						 for (j=lednum; j>0; j--)
						 {
							 off();
						 }
						 SysCtlDelay(4000000);
						 allzero();
						 for (j=lednum; j>0; j--)
						 {
							 fullpurple();
						 }
    		 		 }
    		 }
    		 begin++;
    		 flag1 = 0;
    		 flag2 = 0;
    		 flag3 = 0;
    		 flag4 = 0;
    	}
    	while(1)
    	{
    		allzero();
    		int j;
    	    for(j=lednum;j>0;j--)
    	    {
    	    	off();
    	    }
    	    allzero();
    	    SysCtlDelay(2000000);
    	    for(j=lednum;j>0;j--)
    	    {
    	    	fullred();
    	    }
    	    SysCtlDelay(2000000);
    	}

    }
