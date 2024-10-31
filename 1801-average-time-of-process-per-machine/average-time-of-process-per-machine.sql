# Write your MySQL query statement below
select e.machine_id as machine_id,round(-avg(e.timestamp-d.timestamp),3) as processing_time
from activity as e join activity as d on e.machine_id = d.machine_id and e.process_id = d.process_id and e.activity_type = 'start' and d.activity_type = 'end' group by e.machine_id