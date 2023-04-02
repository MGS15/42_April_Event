<?php

$break = true;

while ($break)
{
	$stdin = fopen('php://stdin', 'r');
	$mac_choices = ['rock', 'paper', 'scissor'];
	$choice_eval["rock"] = ["scissor", "paper"];
	$choice_eval["paper"] = ["rock", "scissor"];
	$choice_eval["scissor"] = ["paper", "rock"];
	if (!$stdin)
	{
		echo "stdin not found\n";
		exit(1);
	}
	echo "Choose rock, paper, or scissors: ";
	$user_choice = fgets($stdin);
	$user_choice = str_replace(PHP_EOL , "", $user_choice);
	if (!in_array($user_choice, $mac_choices))
	{
		echo "Please choose rock, paper, or scissors!" . PHP_EOL;
		continue ;
	}
	$key = array_rand($mac_choices);
	if ($mac_choices[$key] == $user_choice)
	{
		echo "Same choice: $user_choice. Try again." . PHP_EOL;
		continue ;
	}
	if (array_search($user_choice, $choice_eval[$mac_choices[$key]]) == 1)
		echo "Congratulations! You won! The computer chose " . $mac_choices[$key] . PHP_EOL;
	else
		echo "Sorry, you lost. The computer chose " . $mac_choices[$key] . PHP_EOL;
	$break = false;
}
