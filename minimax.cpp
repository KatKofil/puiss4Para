

int best_move(plateau grid, int depth, std::byte player){

	int neutral_valu = std::numeric_limits<int>::min(); //0x80000000
	std::vector<int> choix;

	for(auto m : grid.move_dispo()){
		plateau tmp = grid;
		tmp.play(m)
	}




}

int Minimax(node_t node, int depth, std::byte player)
