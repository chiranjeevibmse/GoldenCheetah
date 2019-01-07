package com.svlabs.svt.ride;

public class SaarRideFileReader {
	static {
		System.loadLibrary("GoldenCheetah");
	}
	public native RideFilePoint[] readFile(String filePath);
}
