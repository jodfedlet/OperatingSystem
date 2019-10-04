running_base_cnt = 0;
rand = lottery_random();
lottery_number(rand%total_base_r_tkts)+1;
lottery_number = lottery_number < 0 -lottery_number : lottery_number;
/*loop through processes on runqueue to do lottery
convert process ticket to base tickets and select winner.*/
list_for_each(tmp, &runqueue_head){
	p = list_entry(tmp, struct task_struct, run_list);
	/*tmp _base_cnt is the process's process tickets scaled into base ticket
	units; plug any compensation ticketes that the process holds*/
	tmp_base_cnt = ((p->user->user_base_tickets*p->process_tkts)\/p->user->user_tpt)+p->process_comp_tkts;
	/*need to be sure that in cases where user_base_tickets < user_tpt
	there's at least one ticket for the process*/
	tmp_base_cnt = tmp_base_cnt < 1 ? 1 : tmp_base_cnt;

	running_base_cnt += tmp_base_cnt;
	/*unlikely() is the case where we lost tickets via integer division 
	trucantion, and we want to award the win to the last process in the runqueue*/
	if((running_base_cnt >= lottery_number) || unlikely(tmp->next == &runqueue_head)){
		if(can_schedule(p, this_cpu)){
			next = p;
			total_base_r_tkts -= next->process_comp_tkts;
			/*process won... zero compensation tickets */
			next->process_comp_tkts = 0;
			next->lott_wins++;
			break;
		}
		else{
			printf("can_schedule failed, not handled in lottery scheduling \n");
			BUG();	
		}
	}

}	