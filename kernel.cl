kernel void square(global float* input, global float* output){
    size_t t = get_global_id(0);
    output[t] = input[t] * input[t];
}