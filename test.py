from pyecharts.charts import Gauge
from pyecharts import options as opts

g = (
    Gauge()
    .add("", [("完成率", 66.6)])
    .set_global_opts(title_opts=opts.TitleOpts(title="Gauge-基本示例"))

)
g.render_notebook()


print(g)
