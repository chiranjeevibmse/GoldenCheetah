package com.svlabs.svt.ride;

public class RideFilePoint {
	// recorded data
    public double secs, cad, hr, km, kph, nm, watts, alt, lon, lat, headwind, slope, temp;

    // pedals
    double lrbalance, lte, rte, lps, rps;
    double lpco, rpco; // left and right platform center offset
    double lppb, rppb, lppe, rppe; // left and right power phase begin/end
    double lpppb, rpppb, lpppe, rpppe; // left and right begin and end peak power phase

    // oxy
    double smo2, thb;

    // acceleration in watts/s km/s
    double hrd, cadd, kphd, nmd, wattsd;

    // running data
    double rvert, rcad, rcontact;

    // core temperature
    double tcore;

    int interval;

    // derived data (we calculate it)
    // xPower, normalised power, aPower
    double xp, np, apower, atiss, antiss, gear, hhb, o2hb, clength;

    @Override
    public String toString() {
    	 return "Sec : "+this.secs+" HR : "+this.hr+" KM : "+this.km+ " Long : "+this.lon+" Lat : "+this.lat;
    }
}
