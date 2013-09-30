Gem::Specification.new do |s|
  s.name = "lzss"
  s.version = "0.1"
  s.author = "NS, FX"
  s.homepage = "http://rednaxelafx.javaeye.com"
  s.platform = Gem::Platform::RUBY
  s.summary = "lzss compress algorithm for ruby"
  s.required_ruby_version = ">=1.9.0"

  s.files = %w[src src/lzss.c src/lzss-ext.c src/extconf.rb example example/example.rb lib lib/compress]
  s.extensions = ["src/extconf.rb"]
  s.require_paths = ["lib"]
  s.rubygems_version = '1.3.6'
  #s.has_rdoc = true
  #s.extra_rdoc_files = ["README.rdoc"]
end
