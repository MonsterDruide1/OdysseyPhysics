#version 310 es
precision mediump float;

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;
in vec3 fragNormal;
in vec3 fragPosition;

// Input uniform values
uniform sampler2D texture0;
uniform vec4 colDiffuse;

uniform vec3 cameraDirection;

// Output fragment color
out vec4 finalColor;


//inspired by blender checker texture node
float checker(vec3 p, float checkerSize)
{
	float x = p.x/checkerSize;
	float y = p.y/checkerSize;
	float z = p.z/checkerSize;

	if (floor(mod(y,2.0)) == 0.0) {
		if (floor(mod(x,2.0)) != floor(mod(z,2.0)))
			return 1.0;
		else
			return 0.0;
	} else {
		if (floor(mod(x,2.0)) == floor(mod(z,2.0)))
			return 1.0;
		else
			return 0.0;
	}
}

void main()
{
    // Texel color fetching from texture sampler
    //vec4 texelColor = texture(texture0, fragTexCoord);

    // NOTE: Implement here your fragment shader code

    float dn = dot(fragNormal,-cameraDirection);

    float lighting = clamp(0.25+dn*0.5,0.0,1.0);

	vec4 color;
	if(fragColor.a == 0.0)
		color = colDiffuse;
	else
		color = fragColor;
    finalColor = vec4(vec3(lighting+checker(fragPosition, 100.0)*0.1),1.0) * color;
}

