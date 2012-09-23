package main.GraphAlgorithms.PathFinding;

import java.util.*;

public class Floyds {
	/* 
	 This assumes that the Adjacency Matrix has already been constructed,
	 that if there is no connection between two nodes that it is sufficiently large
	 and that the connection between a node and itself is 0
	 */
	public int[][] floyds(int[][] adjacencyMatrix) {
		// Used as infinity
		final int I = Integer.MAX_VALUE;
		
		int[][] aMatrix = adjacencyMatrix;
		int n = aMatrix.length;
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (aMatrix[i][k] != I && aMatrix[k][j] != I && aMatrix[i][k] + aMatrix[k][j] < aMatrix[i][j]) {
						aMatrix[i][j] = aMatrix[i][k] + aMatrix[k][j];
					}
				}
			}
		}
		return aMatrix;
	}
	/*
	 Integer is used instead of int because we wish to allow the possibility of an entry
	 being "null", which is otherwise impossible. More specifically, we want entries in
	 nextMatrix to be null when the relationship to adjacencyMatrix turns up an "Infinity".
	 Likewise, we need to allow Integer to equal infinity (or just the max).
		
	 This implementation of Floyds will allow us to re-establish the path instesad of being
	 limited to only the shortest distance, the time complexity is the same but the code
	 complexity is a little more involved.
	 */
	Integer[][] globalAdjacencyMatrix;
	Integer[][] globalNextMatrix;

	public ArrayList<Integer[][]> floyds(Integer[][] adjacencyMatrix, Integer[][] nextMatrix) {
		// Used as infinity
		final int I = Integer.MAX_VALUE;
		
		ArrayList<Integer[][]> Matrices = new ArrayList<Integer[][]>();
		Integer[][] aMatrix = adjacencyMatrix;
		int n = aMatrix.length;
		if (nextMatrix == null) //passing next is optional
		{
			nextMatrix = new Integer[n][n];
		}

		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (aMatrix[i][k] != I && aMatrix[k][j] != I
							&& aMatrix[i][k] + aMatrix[k][j] < aMatrix[i][j]) {
						aMatrix[i][j] = new Integer(aMatrix[i][k] + aMatrix[k][j]);
						nextMatrix[i][j] = new Integer(k);
					}
				}
			}
		}

		//This is done to allow getPath to talk with these matrices (for testing purposes)
		globalAdjacencyMatrix = aMatrix;
		globalNextMatrix = nextMatrix;
		Matrices.add(aMatrix);
		Matrices.add(nextMatrix);

		return Matrices;
	}

	/* 
	 getPath assumes it has adjacencyMatrix and nextMatrix in scope, as well as an "infinity"
	 */
	public String getPath(int i, int j) {
		// Used as infinity
		final int I = Integer.MAX_VALUE;
		
		if (globalAdjacencyMatrix[i][j] >= I) // >= just in case
		{
			return "no path";
		}
		Integer intermediate = globalNextMatrix[i][j];
		if (intermediate == null) {
			return " "; //There is an edge from i to j, with no vertices between
		} else {
			return getPath(i, intermediate) + intermediate.toString() + getPath(intermediate, j);
		}
	}
}
