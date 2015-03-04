
# Sample script using the Zero module

include Zero

class MyTest < Test
  def initialize
	@update_count = 0
    #self.print('MyTest Initialized')
  end
  
  def update
    @update_count+=1
	if((@update_count % 1000000) == 0)
	  $time = Time.now - $time
	  $avg += $time
	  puts "#{(@update_count / 100000)}% : #{$time} sec"
	  $time = Time.now
	end
	
	if(@update_count == 10000000)
	  $avg = $avg / 10
	  perSec = (1 / $avg) * 1000000
	  puts "Results: averaged #{perSec.floor} updates per second.                        "
	  $avg = 0
	  @update_count = 0
	end
  end
end

$testObj = MyTest.new
$time = Time.now
$avg = 0

def update
  $testObj.update
end
