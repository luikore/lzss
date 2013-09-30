require "compress/lzss"

# read
data = File.binread('kiss.rmvb')
# compress
data = Compress::LZSS.encode data
# write
File.open 'kiss.lzss', 'wb' do |f|
  f << data
end

# read
data = File.binread('kiss.lzss')
# de compress
data = Compress::LZSS.decode data
# write
File.open 'kiss2.rmvb', 'wb' do |f|
  f << data
end
