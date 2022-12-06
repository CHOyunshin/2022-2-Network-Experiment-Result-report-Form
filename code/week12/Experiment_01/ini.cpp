# Experiment 1-1 
[PureAloha1]
description = "pure Aloha, overloaded"
# too frequent transmissions result in high collision rate and low channel utilization
Aloha.host[*].iaTime = exponential(2s)

# Experiment 1-2
[PureAloha2]
description = "pure Aloha, optimal load"
# near optimal load, channel utilization is near theoretical maximum 1/2e
Aloha.host[*].iaTime = exponential(6s)

# Experiment 1-3
[SlottedAloha1]
description = "slotted Aloha, overloaded"
# slotTime = pkLen/txRate = 960/9600 = 0.1s
Aloha.slotTime = 100ms
# too frequent transmissions result in high collision rate and low channel utilization
Aloha.host[*].iaTime = exponential(0.5s)

# Experiment 1-4
[SlottedAloha2]
description = "slotted Aloha, optimal load"
# slotTime = pkLen/txRate = 960/9600 = 0.1s
Aloha.slotTime = 100ms
# near optimal load, channel utilization is near theoretical maximum 1/e
Aloha.host[*].iaTime = exponential(2s)