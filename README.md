# mruby-strscan   [![build](https://github.com/okuramasafumi/mruby-strscan/actions/workflows/ci.yml/badge.svg)](https://github.com/okuramasafumi/mruby-strscan/actions/workflows/ci.yml)
StringScanner class
## install by mrbgems
- add conf.gem line to `build_config.rb`

```ruby
MRuby::Build.new do |conf|

    # ... (snip) ...

    conf.gem :github => 'okuramasafumi/mruby-strscan'
end
```
## example
```ruby
p StringScanner.hi
#=> "hi!!"
t = StringScanner.new "hello"
p t.hello
#=> "hello"
p t.bye
#=> "hello bye"
```

## License
under the MIT License:
- see LICENSE file
