#version 120

uniform vec2 resolution;
uniform sampler2DRect texture;
uniform float time;
uniform float rand;
uniform float screenWidth;
uniform float screenHeight;

varying vec2 vTexCoord;

const float pi = 3.145;

bool isActive(vec4 color){
    if(length(color.g) > 0.8){
        return true;
    } else {
        return false;
    }
}

vec4 lifegame(sampler2DRect tex) {
    vec4 mycolor = texture2DRect(tex, vTexCoord);
    bool mystate = isActive(mycolor);
    vec4 colors[8];
    bool states[8];
    int num = 0;
    colors[0] = texture2DRect(tex, vTexCoord + vec2(1.0, 0.0));
    colors[1] = texture2DRect(tex, vTexCoord + vec2(-1.0, 0.0));
    colors[2] = texture2DRect(tex, vTexCoord + vec2(0.0, 1.0));
    colors[3] = texture2DRect(tex, vTexCoord + vec2(0.0, -1.0));
    colors[4] = texture2DRect(tex, vTexCoord + vec2(1.0, 1.0));
    colors[4] = texture2DRect(tex, vTexCoord + vec2(1.0, 1.0));
    colors[5] = texture2DRect(tex, vTexCoord + vec2(-1.0, 1.0));
    colors[6] = texture2DRect(tex, vTexCoord + vec2(1.0, -1.0));
    colors[7] = texture2DRect(tex, vTexCoord + vec2(-1.0, -1.0));
    for(int i = 0; i < 8; i++){
        states[i] = isActive(colors[i]);
        if(states[i]){
            num++;
        }
    }
    if(mystate){
        if(num == 2 || num == 3){
            mystate = true;
        } else {
            mystate = false;
        }
    } else {
        if(num == 3){
            mystate = true;
        } else {
            mystate = false;
        }
    }
    
    if(mystate){
        return vec4(0.0,1.0,0.0,1.0);
    } else {
        return vec4(0.0,0.0,0.0,1.0);
    }
}

void main() {
    vec4 color = lifegame(texture);
    gl_FragColor = vec4(color.r, color.g, color.b, 1.0);
}

