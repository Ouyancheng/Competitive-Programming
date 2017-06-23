import java.util.Scanner;
import java.util.ArrayList;

class Block {
	int num,index,seq;

	public Block(int n,int i,int s) {
		num = n;
		index = i;
		seq = s;
	}
}

class Blocks {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int numOfBlocks = in.nextInt();
		ArrayList<ArrayList<Block>> blocks = new ArrayList<ArrayList<Block>>();
		Block[] blocksPos = new Block[numOfBlocks];
		blocks.add(new ArrayList<Block>(numOfBlocks));

		for(int i = 0; i < numOfBlocks; i++) {
			blocksPos[i] = new Block(i,i,0);
			blocks.add(new ArrayList<Block>());
			blocks.get(i).add(blocksPos[i]);
		}

		// Throw away the rest of the line
		in.nextLine();
	
		while(true) {
			String[] line = in.nextLine().split("\\s+");
			
			if(line.length == 1) {
				break;
			} else {
				int a = Integer.parseInt(line[1]), b = Integer.parseInt(line[3]);
				if (blocks.get(blocksPos[a].index) == blocks.get(blocksPos[b].index)) continue; 
				switch(line[0]) {
					case "move":
						removeFrom(a,blocksPos,blocks);
						if(line[2].equals("onto")) {
							removeFrom(b,blocksPos,blocks);
						}
						addTo(a,b,blocksPos,blocks);
						break;
					case "pile":
						if(line[2].equals("onto")) {
							removeFrom(b,blocksPos,blocks);
						}
						addTo(a,b,blocksPos,blocks);
						break;
				}
			}
		}			
		for(int a = 0; a < blocks.size() - 1; a++) {
				ArrayList<Block> cur = blocks.get(a);
				System.out.print(a + ":");
				for(int l = 0; l < cur.size(); l++) {
					System.out.print(" " + cur.get(l).num);
				}
				System.out.println();
		}
	}

	public static void removeFrom(int i,Block[] blocksPos,ArrayList<ArrayList<Block>> blocks) {
		ArrayList<Block> tQueue = blocks.get(blocksPos[i].index);
		while(tQueue.get(tQueue.size()-1) != blocksPos[i]) {
			Block b = tQueue.remove(tQueue.size()-1);
			ArrayList<Block> dst = blocks.get(b.index);
			b.index = b.num;
			b.seq = dst.size();
			dst.add(b);
		}
	}

	public static void addTo(int src,int tgt,Block[] blocksPos,ArrayList<ArrayList<Block>> blocks) {
		ArrayList<Block> sQueue = blocks.get(blocksPos[src].index);
		ArrayList<Block> tQueue = blocks.get(blocksPos[tgt].index);
		int loopCount = sQueue.size() - blocksPos[src].seq;
		int toRemove = blocksPos[src].seq;
		for(int s = 0; s < loopCount; s++) {
			Block b = sQueue.remove(toRemove);
			b.index = blocksPos[tgt].index;
			b.seq = tQueue.size();
			tQueue.add(b);
		}
	}
}