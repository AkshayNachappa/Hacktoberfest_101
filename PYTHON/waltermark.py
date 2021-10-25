from pyffmpeg import FFmpeg

input_file = 'C:/caminho/input.mp4'
output = 'C:/caminho/output.mp4'
caminho_img="image.jpg"
ff = FFmpeg()
string = '-i {} -i {} -filter_complex "[1:v]scale=25:20[wat];[0:v][wat]overlay=10:main_h-overlay_h-10[outv]" -map "[outv]" -map 0:a {}'.format(input_file,caminho_img, output)
f = ff.options(string)
print(f)