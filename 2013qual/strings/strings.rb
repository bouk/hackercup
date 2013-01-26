m = gets.chomp.to_i

m.times do |i|
  h = Hash[('a'..'z').zip [0] * 26]
  gets.chomp.downcase.each_char do |c|
    if 'a' <= c and c <= 'z'
      h[c] += 1
    end
  end
  optimal = h.to_a.map { |key, value| value }.sort.zip((1..26)).map { |a, b| a * b }.reduce(0, :+)
  puts "Case ##{i + 1}: #{optimal}"
end
