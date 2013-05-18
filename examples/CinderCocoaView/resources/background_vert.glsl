#version 120

#define pi 2.141592653589793238462643383279

uniform float timeValX = 1.0;
uniform float timeValY = 1.0;
// brightness/saturation
float brightness = 0.6;
float minBrightness = 0.05;

uniform float time;
uniform vec2 resolution;

float tscale = 1.1;

// adjust the speed at which gradients reposition in "waves"
float timeSpeed = 0.2;
// stage scale
float stageScale = 1.4; // best under 0.27 or else color overlays get blown out towards the top

float wave(vec2 position, float freq, float height, float speed) {
	float result = sin(position.x*freq - time*timeSpeed*speed);
	result = result * 3.0 - 0.25;
	result *= height;
	result *= brightness; // mutes the colors a bit so they're not so saturated
	return result;
}
vec3 combo(vec2 position, float center, float size) {
	float offset = pi * (center - 0.35);
	float lum   = abs(tan(position.y * pi + offset)) - pi/3.0;
	lum *= size;
	float red   = wave(position, 1.0, 0.9*size, 1.2) + minBrightness;
	float green = wave(position, 3.5, 0.5*size, 1.4) + minBrightness;
	float blue  = wave(position, 1.5, 1.2*size, 1.42) + minBrightness;
	return vec3( lum + red, lum + green, lum + blue );
}

void main(){
	vec4 pos = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex * stageScale;
	gl_Position = pos;
	
	vec2 position = gl_Position.xy / resolution.xy;
	vec3 result = vec3(0.0, 0.0, 0.0);
	result += combo(position, 0.1+0.1*sin(0.1*time + 4.0*position.x), 0.05);
	result += combo(position, 0.5+0.05*sin(0.25*time + 3.0*position.x), 0.25);
	result += combo(position, 0.75+0.05*sin(0.2*time + 1.3*position.x), 0.05);
	result *= brightness;
	gl_FrontColor = vec4(result, 1.0);
}

