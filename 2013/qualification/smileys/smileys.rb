T = gets.chomp.to_i

def go(string, pos, open)
  return open == 0 if pos >= string.length

  c = string[pos]
  if ('a'..'z').include? c or c == ' '
    return go(string, pos + 1, open)
  elsif c == ':'
    if [')', '('].include? string[pos + 1]
      return true if go(string, pos + 2, open)
    end
    return go(string, pos + 1, open)
  elsif c == '('
    return go(string, pos + 1, open + 1)
  elsif c == ')'
    return (open > 0 and go(string, pos + 1, open - 1))
  end

  false
end

T.times do |c|
  s = gets.chomp
  valid = go(s, 0, 0)
  message = valid ? "YES" : "NO"
  puts "Case ##{c + 1}: #{message}"
end
